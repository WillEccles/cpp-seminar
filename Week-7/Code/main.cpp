#include <iostream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// start with the if
	cout << "What is your name?" << endl;

	string name;

	getline(cin, name);

	// this if works the same way as everything else pretty much
	if (name == "will") {
		cout << "You're cool!" << endl;
	}
	else {
		cout << "Ew." << endl;
	}

	// the next thing is a case statement
	// this is also the same as everything else
	cout << "Give me a number." << endl;

	int number;

	cin >> number;

	switch(number) {
	case 1:
		cout << "This is a one." << endl;
		break;
	case 420:
		cout << "You know what's good ;)" << endl;
		break;
	case 42:
		cout << "You said 42... ";
		// this doesn't say break: C++ will let it fall through
		// when it's 42, this will go to default as well, since it won't break
	default:
		// this will show if it's 42 OR any other number, since the 42 case doesn't break
		cout << "You gave me a number." << endl;
		break;
	}

	try {
		if (number == 38) {
			// this will go to the catch and set e to 38
			throw 38;
		}
		// error code 0 = no problem, which is why the programs returns 0
		else throw 0;
	} catch (int e) {
		cout << "Error code: " << e << endl;
	}

	system("pause");
	
	return 0;
}
