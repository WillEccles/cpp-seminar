#pragma once

#include <string>
#include <map>

// color codes for printing in color
#define BLACK 0
#define DARKBLUE 1
#define DARKGREEN 2
#define DARKTEAL 3
#define DARKRED 4
#define DARKMAGENTA 5
#define DARKYELLOW 6
#define DARKWHITE 7
#define DARKGREY 8
#define BLUE 9
#define GREEN 10
#define TEAL 11
#define RED 12
#define MAGENTA 13
#define YELLOW 14
#define WHITE 15

using namespace std;

class IOManager
{
public:
	IOManager();
	IOManager(int);
	void printlc(string, int);
	void clear();
	void wait();
	void wait(string);
	string randomword();
	void loadwords();
	char getin();
	void printc(string, int);
	void setColor(int);
	int DEFAULT;
	map<string, int> getBestScore();
	void saveScore(int, int);
	bool fileExists(char[]);
};
