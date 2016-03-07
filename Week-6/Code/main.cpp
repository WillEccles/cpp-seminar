#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

/*
NOTE: This example code also goes over the bitwise operators a bit.
This is not in my journal.
*/

int _tmain(int argc, _TCHAR* argv[])
{
	// simple math operators are just how you think they should be
	cout << "5 + 6 = " << (5 + 6) << endl;
	cout << "6 - 5 = " << (6 - 5) << endl;
	cout << "6 * 5 = " << (6 * 5) << endl;
	cout << "6 / 2 = " << (6 / 2) << endl;

	// to use expnents you need to include math.h
	cout << "5 squared = " << pow((double)5, (double)2) << endl; // cast to doubles so it doesnt complain
	cout << "Square root of 25 = " << sqrt((double) 25) << endl;
	
	// bitwise
	cout << "5 << 1 = " << (5 << 1) << endl;
	cout << "5 >> 1 = " << (5 >> 1) << endl;
	cout << "8 XOR 7 = " << (8 ^ 7) << endl;
	cout << "All of the binary oper8ors ar"; // cutting this line too keep my beautiful line lengths
	cout << "e like you'd expect. " << endl;

	system("pause");

	return 0;
}

