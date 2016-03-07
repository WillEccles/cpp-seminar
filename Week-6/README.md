# Week 6 - Operators

This week's objective was to get the hang of the various operators in C++.

Since most of them are very basic, this will most likely be a short journal.

## Basic Math

`+`: This is the 'plus' sign we have been using since kindergarten.

```c++
int add = 5 + 5; // 10
std::cout << "5 + 5 = " << add;
```

`-`: This is the 'minus' sign. Same as you think it is.

```c++
int subtract = 10 - 5; // 5
std::cout << "10 - 5 = " << subtract;
```

`*`: The multiplication sign. Also make pointers, but that is a different journal.

```c++
int mult = 5 * 5; // 25
std::cout << "5 * 5 = " << mult;
```

`/`: The division sign.

```c++
int divide = 25 / 5; // 5
std::cout << "25 / 5 = " << divide;
```

## Exponents

One thing you should *never* try to do is use `x ^ y` to raise `x` to the `y` power. This is because in C++, the `^` is the bitwise XOR operator. This means that doing `4 ^ 2` does not result in 16. Instead, it will be 6. This is because `0100 XOR 0010` = `0110`. In order to raise a number to a power, you need to use a method in `math.h`.

```c++
#include <math.h>

int power = pow(5, 2); // 25
std::cout << "5 ^ 2 = " << power;
```

## Example Code

Here is my example code, made proudly in the USA. :us:
