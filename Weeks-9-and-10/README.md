# Weeks 9 & 10 - Arrays
Since week 9 was really just 3 days, I got little done. I am, as such, lumping it in with week 10.

## Basic Arrays
Arrays in C++ are the same as Java and basically every other C-based language, and many others. They are non-mutable, though there are other types (vectors and maps) that are mutable. A non-mutable array cannot change length, and therefore has a predefined length and you cannot simply "add on" to the end of the array.

Here is how to define an array in C++:

```c++
// method 1:
// Type = type of the things in the array
// arrayName = the name of the array
// length = integer value equal to the number of items in the array
Type arrayName[(int) length];

// method 2:
// same as above, but you implicitly define the length - the number of items in the array = the length
Type arrayName[] = {item1, item2, item3}; // length of 3
```

Arrays in C++ (like every other language I can think of) are 0-indexed. This means that the first item in the list is not item 1, but rather item 0. The last item, assuming it is the third item, is not 3; but rather 2.

Next, let's talk about how to read/write items.

```c++
int myNumbers[] = {1, 1, 2, 3, 5, 8};

// print the first item in the list:
cout << myNumbers[0] << endl;

// replace the first item:
myNumbers[0] = 14;
// myNumbers now looks like this: {14, 1, 2, 3, 5, 8}
```

Finally, here is how to print ALL of the items in an array. This is somewhat more difficult, but is really actually not that hard.

```c++
string words[] = {"this", "is", "cool"};

// let's print everything in the loop
// make a `for` loop that goes from 0 to the length of the array minus 1.
for (int i = 0; i < 3; i++) {
	cout << words[i] << endl;
}
// This can be further simplified by removing the braces, unless you need to do more than one thing each iteration
```

*To be continued.*
