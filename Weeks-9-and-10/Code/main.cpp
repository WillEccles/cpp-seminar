#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// I will make 3 types of arrays:
	//    a standard array
	//    a vector
	//    a map

	// first arrays:
	string myStrings[] = {"This is my first string.", "This is my second string."};

	// first let's print those
	for (int i = 0; i < 2; i++) {
		cout << myStrings[i] << endl;
	}

	// now let's change them
	// since the length is fixed at two, I can't add to the array, only change them
	myStrings[0] = "This is now my third string.";
	myStrings[1] = "This is now my fourth string.";

	// print those
	for (int i = 0; i < 2; i++) {
		cout << myStrings[i] << endl;
	}

	// now let's use a vector: it's like an array but without a fixed size
	vector<string> myVector; // this is now a mutable (changeable) array of strings

	// let's add a few things
	myVector.push_back("This is now the first thing here."); // push_back adds a thing to the vector
	myVector.push_back("This is now the second thing here.");

	// print those things
	for (int i = 0; i < 2; i++) {
		cout << myVector[i] << endl;
	}

	// finally comes the map.
	// this one is a key/value pair list
	map<string, string> myMap;
	// this uses strings for both keys and values

	myMap["name"] = "Will";
	myMap["color"] = "white";

	system("pause");

	return 0;
}
