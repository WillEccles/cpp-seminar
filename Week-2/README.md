# Week 2 Journal

This week focused on data types and scope. For scope, there isn't much to talk about until I get to headers, where I'll expand more on scopes.

This program simply dealt with data types and I will touch on scope. A full write-up will be done by Friday, but for now [here is the code](https://github.com/WillEccles/cpp-seminar/tree/master/Week-2/Code).

## Data Types

In this project, I used most major data types, since there are tons of variations of each, and I would not have the time to talk about all of them.

I have compiled a table of data types used in this program:

| Type | Description | Size | Range |
| --- | --- | --- | --- |
| `int` | A 32-bit integer value. | 4B | –2,147,483,648 to 2,147,483,647 |
| `char` | A byte, which will be converted into an ASCII character code if printed directly. | 1B | -127 to 128 |
| `double` | A 64-bit decimal value, called a double since it's twice the size of an integer. | 8B | 1.7E +/- 308 (15 digits) |
| `float` | A 32-bit decimal value. | 4B | 3.4E +/- 38 (7 digits) |
| `string` | A class that basically encapsulates a `char[]`. | Depends on system | N/A |
| `long` | A 64-bit integer value. Just a longer `int`. | 4B | Same as `int` |
| `bool` | A byte that is either true or false (1 or 0). Printing a bool will result in 0 or 1. | 1B | 0 or 1 |

In this example program, I print an explanation of each type and then print an example of each type.

[The output to this program is here.](http://i.imgur.com/LF2fBQX.png) *NOTE: This screenshot does not print a bool because it's old, but [my code](https://github.com/WillEccles/cpp-seminar/blob/master/Week-2/Code/main.cpp) does.*

## Scope

This topic is not going to be a big part of this project, as I will mention it more in the headers project.

For this program, there are some important things to note:
- `using namespace std` makes sure that everything in the `std` namespace (like `cout`, for example) is in scope. Otherwise you would have to reference it using `std::[item]` to tell the compiler what namespace to look in.
- Defining a variable in the `.cpp` file will not make it public. It will always be private unless you define it as public in a header.
- Defining something in a method (such as `main()`) will always be visible only within that method. Not even anywhere else in the same class.

## My code

My code is available [here.](https://github.com/WillEccles/cpp-seminar/blob/master/Week-2/Code/main.cpp)

Made proudly in the USA :us:
