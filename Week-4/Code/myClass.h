#pragma once
// just a note, #pragma once is not best practice, but VS does it automatically so just leave it


/*
This is the header file for myClass. myClass.cpp includes this header, meaning that any method defined in here must be there.
The use of a header is to define methods that are in the class. It does NOT actually contain the code, just the definitions.
This is where I can talk about scope, since I can make things public and private.
*/

class myClass
{
	// these two methods MUST be included in the class file.
	// note that sayHi() is public and actuallySayHi() is private.
	// if I instantiate a myClass in the main method for the program, I can run sayHi() but not actuallySayHi()
public:
	void sayHi();
private:
	void actuallySayHi();
};
