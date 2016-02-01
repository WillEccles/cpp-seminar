#include "stdafx.h"
#include <string>
#include <iostream>

/*
NAME: Will Eccles
SUBJECT: Data Types and Scope
LANGUAGAE: C++

SOME FACTS: By default, anything defined in the field (the area where this comment is) is private.
			In a class header, you can define something under the "public:" list. It'll be public.
			Data types used in this application:
				int
				string
				float
				double
				long
				**Any of these may be used more than once, using, for example, 32-bit or 64-bit versions
*/

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int myInt = 23424;
	string myString = "Hello, I am a string!";
	float myFloat = 17.82394;
	double myDouble = 234.2342;
	char myByte = -127;
	long myLong = 1244235234;

	cout << "Welcome to data types!\n";
	cout << "There are many types of data, for example:\n";
	cout << "   int: 32-bit, signed integer. This goes from -2,147,483,648 to 2,147,483,647" << endl;
	cout << "  char: 8-bit, signed. Goes from -128 to 127" << endl;
	cout << " float: 4-byte decimal, with limits 3.4E +/- 38 (7 digits)" << endl;
	cout << "double: twice the size of a float, hence the name. 1.7E +/- 308 (15 digits)" << endl;
	cout << "  long: a longer int (4 bytes): -2,147,483,648 to 2,147,483,647" << endl;
	cout << " short: a 32-bit int (same as int)" << endl;

	cout << endl << "Let me print some:" << endl;
	cout << myInt << endl;
	cout << myString << endl;
	cout << myFloat << endl;
	cout << myDouble << endl;
	// NOTE: this will print an umlaut, since that's what char number -127 is
	cout << myByte << endl;
	// to print a real byte from that, we can simply cast it to an int
	cout << (int) myByte << endl;
	cout << myLong << endl;

	system("pause");

	return 0;
}

