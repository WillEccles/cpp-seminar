# Week 11 - File IO

File IO in C++ is much easier than anything else I have ever used, except, of course, for bash and other command line environments.

## Reading from a file

Reading from a file is *very* easy in C++. If the file doesn't exist, no errors are even thrown - it just continues as if it read from the file. While this sounds bad because you won't know when the file doesn't exist, this can be overcome. I won't go over doing that here, since this is a basic overview of file input.

Before reading from a file, you need to do a couple things:

1. Have a text file, which should be in the same place as all your code.
2. `#include <fstream>` (and `<iostream>` if you were to follow all my examples here)

You are now ready to read from a file. There are two ways I do this. First of all, you have to create an `fstream` object. This stands for "filestream."

```c++
#include <fstream>

// make a filestream that will read from myfile.txt
fstream myFile("myfile.txt");
```

Now, here is the first way to read from a file: you can read each line and store parts of it into variables. These "parts" are split up by spaces. They are split by other things, technically, but here we will just use spaces. So what does this method do? How does it work?

Using this method, you have to know how the file is set up. Let's say that this is how `myfile.txt` is set up:

```
mike 14
joe 13
jim 20
this line is fun because it doesn't work how we want it to!
```

Let's say that we want to print how old each of these people are. We need to read each line and store an age. I'll write the code for this and then explain it after.

```c++
#include <fstream>
#include <string>

fstream myfile("myfile.txt"); // myfile.txt is the one above, keep that in mind

string name;
int age;

while (myfile >> name >> age) {
	cout << name << " is " << age << " years old!" << endl;
}

// this is not NEEDED but it is good to do
myfile.close();
```

So how on earth does this work? Basically, you are saying, "while there is another line and it is a `string` and an `int`, store those two things in `name` and `age`." This will only work for lines that match that pattern, so the last line will be ignored. Also, if that line was in the middle of the file, it would ignore it as well. In this case, we look through the file and find any `string` and `int` and store them in the `name` and `age` variables we made above. We can then print these values using `cout`.

Now, you may be wondering how we can read all the lines when they don't match a specific pattern like before. For example, I want to read every line of the text file below and print them to the console, but don't know what they look like to store them as individual variables.

```
This is the first line!
Here is another line!
This is the last line :(
```

How can I read this? They don't match a pattern! The answer is simple. Make sure you have `#include <iostream>` at the top of your file and then you can use `getline()`, like so:

```c++
#include <fstream>
#include <iostream>
#include <string>

fstream file("mylines.txt"); // mylines.txt is the file I just wrote out above
string line;

while (getline(file, line)) {
	cout << line << endl;
}

file.close();
```

So how does this work? Basically, you look at the file and get each line using `getline()`, while telling it to read from `file` and store the line in `line`. Now, you can print `line` in the while loop. Simple, huh?

## Writing to a file

This is also fairly simple in C++ and takes about the same amount of effort. You have to make sure you have `<fstream>` included and that's about it.

First, make sure you have a file. This is funny - it will run through and "write" to the file even if the file doesn't exist, and without throwing any errors. The end result: you don't have a file with text in it.

Now you can get started. First, you should make an `fstream` like before, but this time we will write to it instead of reading to it. This is extremely easy. In this example code, I will write the line numbers to the file.

```c++
#include <fstream>

fstream outfile("output.txt");

for (int i = 1; i <= 30; i++) {
	outfile << "This is line " << i << "!" << endl;
}

outfile.close();
```

This code works just how it looks. The `outfile` works just like `cout` when you want to write to it, including the `endl` or `"\n"` at the end! The file now has lines 1 through 30 labeled in it.

# Example code

You can view my example [here](code/main.cpp). Made in the USA. :us:
