# Week 1 Journal

Since this was the first week, this journal will probably be somewhat more lengthy than others.

## Background Information

For this class, we will use Visual C++, which is provided by Microsoft. It functions mostly the same as other versions of C++, with some differences due to the IDE/Windows headers that are preincluded.

Another thing to note is that I already know a good amount of C++ (I couldn't help myself).

## What I did this week

This week, I learned about two basic concepts, standard in and standard out. I made a small sample program to demo this.

### Standard Out - Printing to the console

This is a very simple concept. First of all, under your `#include`s, you can put `using namespace std;`. This means that you can just say things like `cout` and `cin` and `string` without using `std::` before it. Since best practice is to use `std::` before everything, I did it this week. However, in the future, I will not be doing that. I will just use `namespace std`. Keep that in mind. Also, during this journal, I will not use `std::` in small code examples because it will simply waste space.

So to print to the console, you simply use a stream called `std::cout`. Since it is a stream, you must use the bitwise shift operators to put things in it. When you put a line into this stream, it can be made of any data type that can be put in a stream. When you print to it, you have to put an end of line charachter (`"\n"` or `std::endl`) at the end of each line or the next thing printed to the console will still be on the same line.

So, here is how to print a line to the console:

```c++
cout << "Hello, World!" << endl;
```

This will print "Hello, World!" to the console. The `endl` at the end of the line makes sure that if I print another thing, it will print on the next line. For example, if I used `cout << "Hello,";` and then use `cout << " , World!\n";`, the console will just show `Hello, World!`.

In order to print on the next line, I would just add a `\n` or `std::endl` at the end to make it continue, like so:

```c++
cout << "Hello, World!\n";
cout << "Hello again, World!" << endl;
```

The console will say this:

```
Hello, World!
Hello again, World!
```

### Standard input - getting user input

To get user input, you will have to use the `std::cin` stream and the `std::getline()` method for best results.

To do this, we will first import the `std::string` class. This requires that you put `#include <string>` at the top of your file.

As an example, I will store the user input in a string and then print it back to the person. The code is like so:

```c++
string input;
getline(cin, input);
```

The first line defines a string called input where we will store the user input. To get the input, we use `std::getline()` to take the next line from `std::cin` and store it in `input`. To print it to the user you would simple use `cout << input;`.

## How to view my sample program:

If you simply click on [this link](https://github.com/WillEccles/cpp-seminar/tree/master/Week-1/Sample-Code), you will be taken to a folder containing the code for the program. Made proudly in the USA. :us:
