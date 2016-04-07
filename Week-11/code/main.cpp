#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// there are a couple ways to read a file
	// file1.txt - each line is like so:
	//   [key] is [value]

	fstream file("file1.txt");
	string value, is, key;
	
	while (file >> key >> is >> value) {
		// this will put in all lines that match the pattern above
		// key will be set to the first thing
		// value will be set to the value
		// is will be set to is
		// this is good because any line that doesn't match this pattern will be ignored
		cout << key << " is a(n) " << value << endl;
	}

	cout << endl;

	// here is another way:
	fstream file2("file2.txt");
	string line;

	while (getline(file2, line)) {
		cout << "\"" << line << "\"" << endl;
	}

	cout << endl;

	// next let's write to another file
	fstream file3("file3.txt");

	// this works the same as writing to the cout stream since fstream is a file stream
	for (int i = 1; i <= 30; i++) {
		// another thing is that if you run this again, line 42 will set the stream to position 0
		// this means that if you write something new, it will overwrite the file
		// to prevent this, you have to read from the file and then add to the end of that and then..
		//    ..write all of that to the file
		file3 << "This is line " << i << "!" << endl;
	}

	// IMPORTANT NOTE: if the file doesn't exist, there is no error - it just skips the instructions

	cout << "Finished writing to file!" << endl << endl;

	system("pause");

	return 0;
}
