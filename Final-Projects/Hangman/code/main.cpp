#include <iostream>
#include "IOManager.h"
#include <vector>
#include <map>
#include <string>
#include <regex>
#include <algorithm>
#include <exception>
#include <sstream>

// these are why i imported algorithm
#define VCONTAINS(v,c) (find(v.begin(), v.end(), c) != v.end()) // if vector v contains c
#define SCONTAINS(s,c) (s.find(c) != string::npos) // if string s contains c

// this HAS to be changed if using more recent CPP where the to_string method works
// in 2010, this will work, but in later versions it will work the right way, meaning we will get the wrong thing
#define TO_STRING(i) (to_string((long double)i))

using namespace std;

// Windows 7 default color is darkwhite, whereas Windows 10 = WHITE. Hence the constructors.
IOManager io(DARKWHITE);
/*
this is what a complete hangman will look like
_____
|   |
|	O
|  /|\
|   |
|  / \
-------
*/

// map<number of errors, corresponding graphic>
map<int, string> parts;

// take the number of errors and print the hangman accordingly
void drawman(int errs) {
	io.printlc(parts[errs], DARKYELLOW);
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Loading..." << endl;
	
	// prepare for game
	// load all the words from the file
	io.loadwords();
	// load all graphics parts into the map
	parts[0] = "_____\n|   |\n|\n|\n|\n|\n-------"; // no errors
	parts[1] = "_____\n|   |\n|   O\n|\n|\n|\n-------"; // add head
	parts[2] = "_____\n|   |\n|   O\n|   |\n|\n|\n-------"; // head, chest
	parts[3] = "_____\n|   |\n|   O\n|  /|\n|\n|\n-------"; // head, chest, arm 1
	parts[4] = "_____\n|   |\n|   O\n|  /|\\\n|\n|\n-------"; // head, chest, arm 1, arm 2
	parts[5] = "_____\n|   |\n|   O\n|  /|\\\n|   |\n|\n-------"; // head, chest, arm 1, arm 2, stomach
	parts[6] = "_____\n|   |\n|   O\n|  /|\\\n|   |\n|  /\n-------"; // head, chest, arm 1, arm 2, stomach, leg 1
	parts[7] = "_____\n|   |\n|   O\n|  /|\\\n|   |\n|  / \\\n-------"; // head, chest, arm 1, arm 2, stomach, leg 1, leg 2

	// load the best score from file

	io.clear();
	io.printlc("Welcome to Hangman!", WHITE);

	// get best scores
	map<string, int> scorebits = io.getBestScore();
	int bestguesses = scorebits["guesses"];
	int besterrors = scorebits["errors"];

	// display high score
	if (bestguesses != 27 && besterrors != 8) {
		// if the user has previous scores
		io.printc("\nYour high score: ", WHITE);
		io.printc(TO_STRING(bestguesses), YELLOW);
		io.printc(" guesses & ", WHITE);
		io.printc(TO_STRING(besterrors), YELLOW);
		io.printlc(" errors", WHITE);
	}
	else {
		// if the user has no past scores
		io.printlc("\nNo previous scores detected.", DARKYELLOW);
	}

	io.wait("Press enter whenever you are ready to begin.");

	// first we need to get a word
	string word = io.randomword();

	string blanks = ""; // this will be the same length as word, but all blanks

	for (int i = 0; i < word.length(); i++)
		blanks += "_";

	// vector to store letter guesses
	vector<char> guesses;

	int errors = 0;
	int previouserrors = 0;
	bool won = 0;
	bool lost = 0;

	while (!won && !lost) {
		io.clear();

		// if their previous guess was an error
		if (errors > previouserrors) {
			previouserrors = errors;
			
			io.printlc("Sorry, that letter isn't in the word :(", RED);
			cout << endl;
		}

		// print current stats
		stringstream sstr;
		sstr << "Errors: " << errors;
		io.printc(sstr.str(), (errors == 0)?GREEN:RED);
		cout << "; ";
		stringstream sstr2;
		sstr2 << "Guesses: " << guesses.size();
		io.printlc(sstr2.str(), WHITE);

		cout << endl;
		// print current man
		drawman(errors);

		io.printlc("\nYour word: " + blanks, YELLOW);
		cout << endl; // empty line in between

		string input = "";
		// make sure the user puts in at least one letter
		while (input.length() == 0 || input[0] == '\n') {
			input = "";
			cout << "What is your next guess? ";
			try {
				getline(cin, input);
			} catch(exception& e) {
				input = "";
			}

			if (input.length() != 0) {
				// just repeat if the user already guessed it
				if (VCONTAINS(guesses, input[0])) {
					cout << "You already guessed that!" << endl;
					input = ""; // this will fool the while loop into running again
				}
				else guesses.push_back(input[0]);
			}
		}

		// now that we know we have a letter in input[0] that is good...
		// if the word contains that letter
		if (SCONTAINS(word, input[0])) {
			cout << "Good work! '" << input[0] << "' is in the word!" << endl;
			
			// replace all blanks that correspond to that letter with 
			for (int i = 0; i < word.length(); i++)
				if (word[i] == input[0])
					blanks[i] = input[0];
		}
		else {
			errors++;
		}

		if (errors < 7 && blanks == word) {
			// errors can never get to 8 during normal gameplay, so this means that they won.
			won = 1;
		}
		else if (errors == 7) {
			lost = 1;
		}
	}

	io.clear();

	if (won) {
		io.setColor(GREEN);
		cout << "Congratulations, you won!\nYour word was '" << word << ".'" << endl;
		io.setColor(io.DEFAULT);

		io.printc("\nSaving score... ", io.DEFAULT);
		io.saveScore(guesses.size(), errors);
		io.printlc("Saved.", io.DEFAULT);
	}
	else {
		io.setColor(RED);
		cout << "Uh-oh, you didn't do so great...\nThe word was '" << word << ".'" << endl;
		io.setColor(io.DEFAULT);
	}

	io.wait("Press enter to quit.");

	return 0;
}
