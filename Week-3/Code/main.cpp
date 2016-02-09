// functions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// methods (functions) can either return data or not return data.
// this method returns nothing, and the next one returns a number
void sayHi() {
	// when I do "sayHi();" in the main method, it will print "Hi!"
	cout << "Hi!" << endl;
}

// this one returns a number
int life() {
	return 42;
}

// this one has a string input
void say(string message) {
	cout << message << endl;
}

// this one returns an int, which is the sum of the two that are given in the input
int add(int a, int b) {
	return a + b;
}

// notice that the main method is last - this is so it defines the others first so that it can see them
int _tmain(int argc, _TCHAR* argv[])
{
	// say hi
	sayHi();
	// say the meaning of life
	cout << "The meaning of life is " << life() << "!" << endl;
	// say a couple things
	say("This is thing 1");
	cout << "The meaning of life is " << life() << endl;
	// add 5 and 6
	cout << "5 + 6 = " << add(5, 6) << endl;

	cout << badd(5, 6);

	system("pause");
	return 0;
}

