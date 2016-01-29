#include <iostream>
#include <string>

/*
NAME: Will Eccles
PROJECT: Standard IO
LANGUAGE: C++
DATE: 1/27/16

EXPLANATION:
	stdio is done using the cin/cout streams, which use the bitwise shift operators because they are streams of bits.
	For cout, you must terminate the line using either \n or std::endl, or else you will go to print another time and print on the same line as before.
	For cin, you use std::getline(stream, string). This will get the next line from the stream and store it in the string.
*/

// right here, I have commented this out because I didn't use it.
// this would allow me to not put in "std::" before a lot of the stuff
// using namespace std;
// alternatively, you can use "using std::cout" or something and used just "cout" but everything else would use std::

// main method, always returns int
// could also be written as int main() {}, since it doesn't have to require the arguments
int _tmain(int argc, _TCHAR* argv[])
{
	// to print a string
	std::cout << "Hello, World!.\n";
	
	// using an alternative version of the endline
	std::cout << "Hello again, World!" << std::endl;

	// if you added "using namespace std;" before the main method, it would not require "std::" but this is best practice
	// now for some input
	std::string input;

	// this will get the next line from a stream, specifically the standard cin stream.
	std::getline(std::cin, input);

	// repeat the input from the user
	std::cout << "You said '" << input << "'" << std::endl;

	// here is a trick I have learned: if you want to pause to wait for the person (since the program will quit immediately if you are in debug after all is done)
	// this will give the classic "press any key to continue" display on windows. keep in mind, this must be removed from production code.
	// This is a terrible way of doing it - you should write a better method for it, which I did in a separate program.
	// For simply messing with code examples like this, it's fine.
	system("pause");

	// 0 is for all is well, otherwise it shows that it ended with an error/some other code might mean something else
	return 0;

	// from here on out, I will be using namespace std so that I don't have to use std:: before everything.
}
