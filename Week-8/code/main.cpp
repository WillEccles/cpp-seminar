#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// this week is loops
	// first up: for loops
	// these are the same as every other language
	// print every number 1 to 10
	for (int i = 1; i <= 10; i++) {
		cout << i << endl;
	}
	// the other varient (item in array) works as well, but ill do that during the arrays project


	// now a while loop: this will say "nope" until the user enters "ebola"
	string input = "";

	cout << "Say ebola!" << endl;

	while (input != "ebola") {
		getline(cin, input);
	}

	cout << "Ebola!" << endl;

	// and here is a do while loop, which will run at least once.
	int i = 26;
	do {
		cout << i << endl;
	} while (i <= 25);
	// this will print 26, but only once since the condition is not met and it won't run again.

	system("pause");

	return 0;
}

