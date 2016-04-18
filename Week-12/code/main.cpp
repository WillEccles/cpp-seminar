#include <iostream>

using namespace std;

int main()
{
	// this value is not a pointer
	int nonPointer = 45;
	// this sets nonPointer to 45, but its memory address is NOT 45
	// in order to get the memory address, you would do &nonPointer
	// referencing the value of nonPointer this way must be done with a pointer

	// this is myPointer, a pointer
	// its value is not an integer, rather it points to something in memory...
	//   ... that is an integer. in this case it points to nonPointer.
	int *myPointer = &nonPointer;

	// the * operator can be read as "the value pointed to by"
	// therefore line 21 says "the value pointed to by myPointer equals the address of nonPointer"

	cout << "int nonPointer = 45;" << endl << "int *myPointer = &nonPointer;" << endl;
	cout << endl;
	cout << "nonPointer: " << nonPointer << endl;
	// the next two lines are functionally the same: they each to &nonPointer,
	//    and they will print the memory address of nonPointer
	cout << "myPointer: " << myPointer << endl;
	cout << "&nonPointer: " << &nonPointer << endl;
	// to get the value 45 from nonPointer using myPointer you have to do this
	// *myPointer is "the value pointed to by the address of nonPointer"
	// AKA the value of nonPointer
	cout << "*myPointer: " << *myPointer << endl;

	cout << endl;
	system("pause");

	char mystr[] = "ebola";

	return 0;
}
