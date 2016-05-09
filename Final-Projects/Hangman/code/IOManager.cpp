#include "IOManager.h"

#ifdef _WIN32
#include <Windows.h>
#endif

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <time.h>
#include <map>

#ifdef _WIN32
// windows defined max, and I want to use a different one later on, meaning I have to undef this one
#undef max
#endif

using namespace std;

vector<string> words;

int DEFAULT;

#ifdef _WIN32
// this will let me access the console
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
#endif

void IOManager::setColor(int colorCode) {
#ifdef _WIN32
	SetConsoleTextAttribute(console, colorCode);
#endif
}

// because this is better than using 'system("cls")'
void IOManager::clear() {
#ifdef _WIN32
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
		);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
		);
	SetConsoleCursorPosition(console, topLeft);
#else
	// clear the screen on *nix
	cout << "\x1B[2J\x1B[H";
#endif
}

// print a line in a certain color
void IOManager::printlc(string line, int color) {
	setColor(color);
	cout << line << endl;
	setColor(DEFAULT);
}

// print in a certain color, but not with a newline
void IOManager::printc(string text, int color) {
	setColor(color);
	cout << text;
	
}

void IOManager::wait() {
	setColor(DARKWHITE);
	cout << "\nPress ENTER to continue...";
	// this is why i had to undef max, because windows defines it in some header file somewhere
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	setColor(DEFAULT);
}

void IOManager::wait(string message) {
	setColor(DARKWHITE);
	cout << "\n" << message;
	// this is why i had to undef max, because windows defines it in some header file somewhere
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	setColor(DEFAULT);
}

void IOManager::loadwords() {
	fstream file("words.txt");
	string word;

	// for every line in the file, make sure it's just a string (with no delimiters)
	while(file >> word) {
		words.push_back(word);
	}
}

// this will grab a random word from the list of words
string IOManager::randomword() {
	if (words.size() != 0) {
		srand(time(NULL));
		int i = rand() % words.size();
		return words[i];
	} else {
		printlc("Your words.txt file is empty/nonexistent!", RED);
		return "no words found";
	}
}

// read scores
map<string, int> IOManager::getBestScore() {
	// create the file if it doesn't exist
	fileExists("scores.txt");

	fstream scores("scores.txt");

	// since the worst possible is 26, this accounts for finding no scores
	int bestg = 27;
	int beste = 8; // worst is 7 so 8 accounts for no scores

	int guesses, errors;

	while (scores >> guesses >> errors) {
		if (guesses < bestg) {
			bestg = guesses;
			beste = errors;
		}
		else if (guesses == bestg && errors < beste) {
			// this accounts for the same number of guesses but with lower errors
			beste = errors;
		}
	}

	map<string, int> score;

	score["guesses"] = bestg;
	score["errors"] = beste;

	scores.close();

	return score;
}
// save a score
void IOManager::saveScore(int g, int e) {
	// create the file if it doesn't exist
	fileExists("scores.txt");
	
	fstream scores("scores.txt");

	string input = "";

	vector<string> lines;

	while(getline(scores, input)) {
		lines.push_back(input);
		input = "";
	}

	scores.close();

	fstream scores2("scores.txt");

	for (int i = 0; i < lines.size(); i++) {
		scores2 << lines[i] << endl;
	}

	scores2 << g << " " << e << endl;

	scores.close();
}

char IOManager::getin() {
	string input = "";

	while (input.length() == 0 || input[0] == '\n') {
		input = "";
		getline(cin, input);
	}

	return input[0];
}

bool IOManager::fileExists(char filename[]) {
	if (ifstream(filename))
		return true;
	
	ofstream file(filename);
	if (!file) {
		file.close();
		return false;
	}
}

// constructors
IOManager::IOManager() {
	DEFAULT = WHITE;
}

IOManager::IOManager(int defaultColor) {
	DEFAULT = defaultColor;
}
