# Week 7 - Conditionals

This week was all about conditionals. In this journal, I will cover a few:

- if/then/else
- switch case
- try/catch

## If/Then/Else - The most basic.

This is the most basic way to test a value in C++. Here is the basic format:

```c++
if (expression) {
	// code
}
else {
	// other code
}
```

So how does this work? Simple: if the value of `expression` (which MUST be a boolean) is true, it runs what's inside the `if` block, and if it's false it does the else.

Here is a quick example:

```c++
if (5 < 4) {
	cout << "5 is less than 4???" << endl;
}
else {
	cout << "5 is NOT less than 4 :)" << endl;
}
```

Another interesting thing you can do is the `else if` block. This will go between your `if` and your `else`, and you can have as many as you want. This means that if the first `if` is false, it will look through each `else if` and see if those are true. If they are, it will ignore your `else`. It's hard to explain the reason for this, but at some point you will use it and understand why it is useful.

Here is an example:

```c++
if (5 < 4) {
	cout << "5 is less than 4?" << endl;
}
else if (5 == 4) {
	cout << "5 is 4?" << endl;
}
else if (5 <= 4) {
	cout << "5 is less that or equal to 4?" << endl;
}
else {
	cout << "5 > 4." << endl;
}
```

## Switch case - somewhat more advanced.

Switch cases are where you define a bunch of cases, and it looks at a thing and compares them to it. When the case is true it will execute the code after the statement. Here is an example:

```c++
int myValue = 5;

// look through the contained cases to see if they match myValue
switch(myValue) {
	case 1:
		cout << "myValue is 1." << endl;
		break;
	case 2:
		cout << "myValue is 2." << endl;
		break;
	case 3:
		cout << "myValue is 3." << endl;
		break;
	case 4:
		cout << "myValue is 4." << endl;
		break;
	case 5:
		cout << "myValue is 5." << endl;
		break;
	default:
		cout << "None of the above apply." << endl;
}
```

The code should speak for itself, but there are some quirks I should point out. First of all, the value in the switch cannot be a boolean, since that would not be a good use for one. Also, the default case is not needed but it will be run if the above cases do not apply. Finally, when you break the case at the end, that is for good reason. If I removed the `break;` in `case 4:`, it would simply continue and say that `myValue` is 5.

## Try/Catch

This one is fairly simple. These are used when you need to do something, but it has the potential to throw an error which would usually hose your program. Instead, it catches the error (a play on words - throw -> catch) and just does something different. You can throw any value, usually an integer or an exception type. Here is an example:

```c++
try {
	// run the code in here, and if it fails throw an error
	// I am not sure if this code would even work, but it is just an example.
	if (!typeof(value) == int) {
		// in theory (if this code works), it will see that the type of the value is not int.
		// now we will throw an error.
		throw 1;
	}
} catch (int e) {
	// now that it has caught int e, print the error
	cout << "Error: " << e << endl;
}
```

## Example code

[Here](https://github.com/WillEccles/cpp-seminar/blob/master/Week-7/Code/main.cpp) is my code, made in the USA. :us:
