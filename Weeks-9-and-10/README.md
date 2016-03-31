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
// make a 'for' loop that goes from 0 to the length of the array minus 1.
for (int i = 0; i < 3; i++) {
	cout << words[i] << endl;
}
// This can be further simplified by removing the braces, unless you need to do more than one thing each iteration
```

## Vectors
A vector is a type of mutable array. Unlike other arrays, aside from using `std::Array`, which I won't get into, this one must be included. To use it, simply `#include <vector>` and either use `std::vector` or, when using namespace std, you can just use `vector`.

The definition of a vector is simple:
```c++
#include <vector>

std::vector<Type> vName;
```

Here, as above, `Type` is the typename of the things in the vector. For example, a vector full of ints:
```c++
vector<int> myNumbers;
```

Unlike a conventional array, you cannot define a list of things after an `=`. This would result in an error. Instead, you have to add to the end of the array using `std::vector<T>::push_back()`. This will make the vector 1 item longer and add in whatever you pass to the method:
```c++
// create a vector
vector<int> myNumbers;

// add some numbers to it
myNumbers.push_back(12);
myNumbers.push_back(234);
myNumbers.push_back(289347);
```

Now, you might wonder how you can iterate through it if you don't know how long it is, since its length can be changed. In order to do this, you simply ask it how long it is, so to speak.
```c++
// I am going to use the previous vector, so pretend it is defined here

for (int i = 0; i < myNumbers.size(); i++) {
	cout << myNumbers[i] << endl;
}
```

You can also change and read them the same way, by the way - you just use the index in the brackets like the conventional array.

## Maps
Maps are an ordered key/value pair list. This might sound confusing, but let me explain. First, make sure you have `#include <map>` and use namespace std or just `std::map`. This time, you have to use two types:
```c++
std::map<Type, Type2> myMap;
```

The first type is the kind of key, and the second is the type of the values. For example, say I want to save a list of people and their ages. I would make the types a string and an int.
```c++
map<char*, int> peopleAges;
```

To add something to a map, you just do the following:
```c++
map<char*, int> people;

people["Mike"] = 45;
people["Joe"] = 17;
people["Jose"] = 22;
```

This is the same way you read from the list but without the equals sign. It will return the value for the key you put in the brackets. If I want to get Mike's age:
```c++
cout << people["Mike"] << endl;
```

So, before, I said that the map is ordered. What does this mean? This means that the things inside of it are sorted by their keys. For example, if the keys were ints and I put in one under the key of 14 and then one under the key of 2, the first element in the list will be 2, even though it was added second. If you don't want order, you should check out the [`<unordered_map>`](http://www.cplusplus.com/reference/unordered_map/).

# Example Code

My example code can be found [here](Code/main.cpp). Made in the USA. :us:
