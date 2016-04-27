#include <string>
#include <vector>
#include <map>

#ifdef _WIN32
// this makes this windows-specific, this is for arrow keys
#include <conio.h>
#endif

#include "IOManager.h"
#include <fstream>
#include <iostream>
#include <time.h>
#include <algorithm>

// arrow keys key codes
#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_ESCAPE 27

// these are why i imported algorithm
#define VCONTAINS(v,c) (find(v.begin(), v.end(), c) != v.end()) // if vector v contains c
#define SCONTAINS(s,c) (s.find(c) != string::npos) // if string s contains c

#define IS2048 (VCONTAINS(rows[0], 2048) || VCONTAINS(rows[1], 2048) || VCONTAINS(rows[2], 2048) || VCONTAINS(rows[3], 2048))
#define AREBLANKS (VCONTAINS(rows[0], 0) || VCONTAINS(rows[1], 0) || VCONTAINS(rows[2], 0) || VCONTAINS(rows[3], 0))
#define BLANKROW(r) (rows[r][0] + rows[r][1] + rows[r][2] + rows[r][3] == 0)
#define BLANKCOL(c) (rows[0][c] + rows[1][c] + rows[2][c] + rows[3][c] == 0)
#define TO_STRING(i) (to_string((long double) i))

// http://stackoverflow.com/questions/8435923/getting-arrow-keys-from-cin

using namespace std;

IOManager io(DARKWHITE);

map<int, vector<int>> rows;

map<int, int> colors;

bool canmove();
void printTiles();
void newTile();

int main()
{
	if (!ISWINDOWS) {
		cout << "Sorry, but this will not work on your current platform :(" << endl;
		io.wait("Press enter to quit.");
		return 0;
	}

	colors[2] = WHITE;
	colors[4] = YELLOW;
	colors[8] = DARKYELLOW;
	colors[16] = RED;
	colors[32] = DARKRED;
	colors[64] = MAGENTA;
	colors[128] = DARKMAGENTA;
	colors[256] = TEAL;
	colors[512] = DARKTEAL;
	colors[1024] = BLUE;
	colors[2048] = GREEN;

	io.printlc("Welcome to 2048!", WHITE);
	io.printlc("\nUse the arrow keys to move the blocks.", WHITE);
	io.printlc("Hit escape to pause the game.", WHITE);
	io.printc("To win, you must get a ", WHITE);
	io.printc("2048", colors[2048]);
	io.printlc(" tile!", WHITE);
	io.printlc("Good luck!", WHITE);
	io.wait("Press enter to begin (or continue) the game!");

	// either load the old game or determine there should be a new one
	io.fileExists("2048save.txt"); // this returns bool but i don't care right now

	fstream file("2048save.txt");

	int rowNum, n1, n2, n3, n4;

	while (file >> rowNum >> n1 >> n2 >> n3 >> n4) {
		rows[rowNum].push_back(n1);
		rows[rowNum].push_back(n2);
		rows[rowNum].push_back(n3);
		rows[rowNum].push_back(n4);
	}

	file.close();

	// if there is no previous game:
	if (rows.empty()) {

		// first, draw out the grid
		/*
		[ 1 ] [ 2 ] etc
		*/

		for (int i = 0; i < 4; i++) {
			rows[i].push_back(0);
			rows[i].push_back(0);
			rows[i].push_back(0);
			rows[i].push_back(0);
		}

		newTile();
		newTile();

		// so now we should display this and then break out of the if so we can play the game
		printTiles();
	}
	// if there is another game
	else {
		// display previously found number rows
		printTiles();
	}

	// this is where we just catch user input and do other game functions

	while (!IS2048 && canmove()) {
		// while there's no 2048 and you can still move
		int KB_code = 0;

		// this will be used to check if the rows have been changed
		map<int, vector<int>> oldRows = rows;

		while (KB_code == 0)
		{
			if (kbhit())
			{
				KB_code = getch();
				
				switch (KB_code)
				{
					case KB_LEFT:
						// move the tiles left
						for (int r = 0; r < 4; r++) {
							// only do something if there are tiles in the row
							if (!BLANKROW(r)) {
								// start by making sure everything is as far left as possible
								for (int c = 0; c < 3; c++) {
									if (rows[r][c] == 0) {
										rows[r][c] = rows[r][c+1];
										rows[r][c+1] = 0;
									}
								}
								for (int c = 0; c < 3; c++) {
									if (rows[r][c] == 0) {
										rows[r][c] = rows[r][c+1];
										rows[r][c+1] = 0;
									}
								}

								// now we have to merge any tiles that are the same
								for (int c = 0; c < 3; c++) {
									if (rows[r][c] == rows[r][c+1]) {
										rows[r][c] = rows[r][c+1]*2;
										rows[r][c+1] = 0;
									}
								}

								// and now we must shove it all left again :(
								for (int c = 0; c < 3; c++) {
									if (rows[r][c] == 0) {
										rows[r][c] = rows[r][c+1];
										rows[r][c+1] = 0;
									}
								}
								for (int c = 0; c < 3; c++) {
									if (rows[r][c] == 0) {
										rows[r][c] = rows[r][c+1];
										rows[r][c+1] = 0;
									}
								}
							}
						}
						printTiles();
						if (oldRows != rows)
							newTile();
						break;
					case KB_RIGHT:
						// move the tiles right
						for (int r = 0; r < 4; r++) {
							// only do something if there are tiles in the row
							if (!BLANKROW(r)) {
								// start by making sure everything is as far right as possible
								for (int c = 3; c > 0; c--) {
									if (rows[r][c] == 0) {
										rows[r][c] = rows[r][c-1];
										rows[r][c-1] = 0;
									}
								}
								for (int c = 3; c > 0; c--) {
									if (rows[r][c] == 0) {
										rows[r][c] = rows[r][c-1];
										rows[r][c-1] = 0;
									}
								}

								// now we have to merge any tiles that are the same
								for (int c = 3; c > 0; c--) {
									if (rows[r][c] == rows[r][c-1]) {
										rows[r][c] = rows[r][c-1]*2;
										rows[r][c-1] = 0;
									}
								}

								// and now we must shove it all right again :(
								for (int c = 3; c > 0; c--) {
									if (rows[r][c] == 0) {
										rows[r][c] = rows[r][c-1];
										rows[r][c-1] = 0;
									}
								}
								for (int c = 3; c > 0; c--) {
									if (rows[r][c] == 0) {
										rows[r][c] = rows[r][c-1];
										rows[r][c-1] = 0;
									}
								}
							}
						}
						printTiles();
						if (oldRows != rows)
							newTile();
						break;
					case KB_UP:
						// move the tiles up
						for (int c = 0; c < 4; c++) {
							// only proceed if there is at least one tile in the column
							if (!BLANKCOL(c)) {
								// shift tiles up
								for (int r = 0; r < 3; r++) {
									if (rows[r][c] == 0) {
										rows[r][c] = rows[r+1][c];
										rows[r+1][c] = 0;
									}
								}
								for (int r = 0; r < 3; r++) {
									if (rows[r][c] == 0) {
										rows[r][c] = rows[r+1][c];
										rows[r+1][c] = 0;
									}
								}

								// now we have to merge any tiles that are the same
								for (int r = 0; r < 3; r++) {
									if (rows[r][c] == rows[r+1][c]) {
										rows[r][c] = rows[r+1][c]*2;
										rows[r+1][c] = 0;
									}
								}

								// shift tiles up again
								for (int r = 0; r < 3; r++) {
									if (rows[r][c] == 0) {
										rows[r][c] = rows[r+1][c];
										rows[r+1][c] = 0;
									}
								}
								for (int r = 0; r < 3; r++) {
									if (rows[r][c] == 0) {
										rows[r][c] = rows[r+1][c];
										rows[r+1][c] = 0;
									}
								}
							}
						}
						printTiles();
						if (oldRows != rows)
							newTile();
						break;
					case KB_DOWN:
						// move the tiles down
						for (int c = 0; c < 4; c++) {
							// shove all tiles down
							for (int r = 3; r > 0; r--) {
								if (rows[r][c] == 0) {
									rows[r][c] = rows[r-1][c];
									rows[r-1][c] = 0;
								}
							}
							for (int r = 3; r > 0; r--) {
								if (rows[r][c] == 0) {
									rows[r][c] = rows[r-1][c];
									rows[r-1][c] = 0;
								}
							}

							// now we have to merge any tiles that are the same
							for (int r = 3; r > 0; r--) {
								if (rows[r][c] == rows[r-1][c]) {
									rows[r][c] = rows[r-1][c]*2;
									rows[r-1][c] = 0;
								}
							}

							// shove all tiles down again
							for (int r = 3; r > 0; r--) {
								if (rows[r][c] == 0) {
									rows[r][c] = rows[r-1][c];
									rows[r-1][c] = 0;
								}
							}
							for (int r = 3; r > 0; r--) {
								if (rows[r][c] == 0) {
									rows[r][c] = rows[r-1][c];
									rows[r-1][c] = 0;
								}
							}
						}
						printTiles();
						if (oldRows != rows)
							newTile();
						break;
					case KB_ESCAPE:
						io.saveGame(rows);
						io.clear();
						io.wait("Your game has been saved. Enter to quit.");
						return 0;
						break;
				}

				// save the current state of the game
				io.saveGame(rows);

			}
		}
	}
	
	if (IS2048) {
		// this will just clear the save file
		// opening a file using the truncate option clears the file immediately
		ofstream ofs;
		ofs.open("2048save.txt", std::ofstream::out | std::ofstream::trunc);
		ofs.close();

		io.printlc("\nYou won! Congratulations!", GREEN);
		io.wait("Press enter to quit.");
	}
	else {
		// this will just clear the save file
		// opening a file using the truncate option clears the file immediately
		ofstream ofs;
		ofs.open("2048save.txt", std::ofstream::out | std::ofstream::trunc);
		ofs.close();

		io.printlc("\nUnfortunately, you have lost :(", RED);
		io.wait("Press enter to quit.");
	}

	return 0;
}

// this will crawl through the rows and see if there are any moves
bool canmove() {
	// automatically allow movement if there are ANY 0s
	for (int r = 0; r < 4; r++) {
		if (VCONTAINS(rows[r], 0))
			return true;
	}

	// we need to check if none of the tiles can move, meaning that none of their neighbors are the same
	for (int r = 0; r < 4; r++) {
		if (rows[r][0] == rows[r][1] || rows[r][1] == rows[r][2] || rows[r][2] == rows[r][3])
			return true;
	}
	for (int c = 0; c < 4; c++) {
		if (rows[0][c] == rows[1][c] || rows[1][c] == rows[2][c] || rows[2][c] == rows[3][c])
			return true;
	}
	return false;
}

void printTiles() {
	io.clear();

	// first I want to print the score, AKA the sum of all the tiles
	int score = 0;
	for (int r = 0; r < 4; r++)
		for (int c = 0; c < 4; c++)
			score += rows[r][c];

	// get highest tile
	int n = 0;
	for (int r = 0; r < 4; r++)
		for (int c = 0; c < 4; c++)
			n = (rows[r][c] > n) ? rows[r][c] : n;

	// score color set to the color of the high tile
	int scoreColor = colors[n];

	io.printc("Score: ", io.DEFAULT);
	// the color of the score should be the color of the highest tile
	io.printlc(TO_STRING(score) + "\n", scoreColor);

	string numToPrint;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (rows[i][j] == 0) {
				numToPrint = "    ";
			}
			else {
				numToPrint = TO_STRING(rows[i][j]);
				for (int s = 1; s <= 4 - TO_STRING(rows[i][j]).length(); s++)
					numToPrint += " ";
			}
				
			io.printc(" [", io.DEFAULT);
			io.printc(numToPrint, colors[rows[i][j]]);
			io.printc("]", io.DEFAULT);
		}
		cout << endl;
	}
}

void newTile() {
	// after the user makes a move, spawn a new tile
	if (AREBLANKS) {
		// store a list of blank tiles
		vector<vector<int>> blanks;

		for (int r = 0; r < 4; r++) {
			for (int c = 0; c < 4; c++) {
				if (rows[r][c] == 0) {
					vector<int> tile;
					tile.push_back(r);
					tile.push_back(c);
					// store empty tile
					blanks.push_back(tile);
				}
			}
		}

		srand(time(NULL));
		// pick a random blank tile from the list of them
		vector<int> blank = blanks[rand() % blanks.size()];

		// this is a number 0 - 3
		// 25% chance of 4, 75% chance of 2
		// if 0, make it a 4, otherwise make it a 2
		int tile = (rand() % 2) ? 2 : 4;
		// that code is kind of confusing, but it works, trust me.


		// store a number there
		rows[blank[0]][blank[1]] = tile;

		printTiles();
	}
}
