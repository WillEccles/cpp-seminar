// Week 5 Casting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// start with some numbers to cast
	int myint = 455;
	float myfloat = 42.156;
	double mydbl = 420000000000000;

	cout << "here is an int: " << myint << endl;
	cout << "here is a float: " << myfloat << endl;
	cout << "here is a double: " << mydbl << endl;

	cout << endl;

	// lets cast a bit now :D
	cout << "float -> int: " << (int)myfloat << endl;
	// this wont work right since the double is bigger than the int can handle
	cout << "dbl -> int: " << (int)mydbl << endl;
	cout << "int -> float: " << (float)myint << endl;

	// implicit casting
	short A = 12;
	int B = A;

	cout << "I casted " << A << " to " << B << "." << endl;

	system("pause");

	return 0;
}runtime error6;
