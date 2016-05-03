# Week 13 - Hex, bin, and C++

This week, since I have nothing better to do and don't want to write up my hangman app yet, I am going to explain how to convert from a normal integer to binary, to hexadecimal, and how to use these in C++.

## Binary

So, how does binary work? First of all, binary is base 2. This means that there are only *two* numbers. 0 and 1. To convert is actually pretty easy, and works the same as hex (though in a different base). Here is a quick tutorial:

```
0001 -> 1
0010 -> 2
0011 -> 3
0100 -> 4
0101 -> 5
0110 -> 6
```

In case you didn't figure this out, each location in the number from right to left represents a power of 2, starting with 0. Here is a representation of this:

```
 0  0  0  0
[3][2][1][0]
```

This goes on forever, so past 3 would be 4, and so on and so forth. This is the power 2 is raised to if that bit is 1. So in other words, you can look at each "box" above (each bit) as saying *(2<sup>n</sup> * x)*, where *x* is the value, 0 or 1, and *n* is the position from the right, starting from 0, as shown above. To read a number that is in binary form, simply add all of these together:

```
0101
(2^0 * 1) + (2^1 * 0) + (2^2 * 1) + (2^3 * 0) = 5
```

Hopefully that makes sense. So basically, the *values* of each bit are as follows: `[8][4][2][1]`, which continues to the left as long as you want. Putting a 1 in one of these spots says to add that number, putting a 0 says not to.

## Hexadecimal

Hex is very odd. Hex is base 16, meaning that there are 16 integers. How does this work, and why on earth did they create it!? Well, let's start with how it works, and we can talk about why it exists later.

First of all, since there is no single number that represents 15, which is the max since it starts at 0, you have to use something else. Here, we use `1, 2, 3, 4, 5, 6, 7, 8, 9, 10, A, B, C, D, E, F`. To write these, some languages use the prefix of `0x`, which C++ does, and others may prefix it with a `#`. In some languages, like C++, you can simply write the number without the `0x` or other prefix.

How does this work? Well, it works pretty much the same as before, but differently since it is base 16. It still goes right to left, so `0x000F` is 15. A difference, however, is that **a single hex digit is two digits**, which does not make sense when you read it, but you will understand in a second. The max value of one of these is 255, since it would be 256 (16<sup>2</sup>) *not* including 0. This means that it goes like so:

```
00 -> 0, min
FF -> 255, max
```

The formula for binary was using *2<sup>n</sup>*, but this one just uses *16<sup>n</sup>*. Otherwise, it works the same, one of the 16 numbers, reading from right to left.

Examples:

```
0x000F -> 15
0x0F0F -> 3855
```

Funny enough, each one of these numbers, 0-F, represents a *nybble*, which is half of a *byte*, which is 8 bits. The nybble is just 4 bits. An F represents a full `1111`, and a 0 is a `0000`. Each in between is represented here too. If you want to see this in action, go to the Windows Calculator app and do `view > programmer`. Now, choose the *hex* option on the left and click the F button. You'll see the first nybble from the right (since this is all left to right) become `1111`.

**So why was this created?**

The answer is probably simpler than you think. Back when computers were first being made more powerful and RAM was starting to add up to kilobytes and kilobytes (maybe even megabytes!), they needed a way to reach *every* address in memory without making numbers that are enourmous. With the hex system, it is easily comparable to binary, which the computer understands very well, and large numbers take up much smaller spaces than its decimal counterpart. Make sense now?

## How to use these in C++ (WIP)

First we will talk about hex in C++, since it is built in and supported as literals, meaning you can actually write the hexadecimal integer instead of using some fancy thing to convert. With binary, you can't just write `001001010`, since it will see this as `1,001,010`, since the zeroes can just be removed since they are leading zeroes and are therefore unnecessary.

**Hex in C++**

First of all, you can define a plain old `int` with its value as a hexadecimal literal, as long as you have the `0x` prefix. For example, let's make an `int` equal to 15 (F):

```c++
int myhex = 0xF
```

When you print this to the console, it will write this as `15`, which is not what you want if you just want to see the value. Fortunately, you can use the built-in `to_string()` method to take care of this. I'll let you figure that out on your own.

How can you convert from an integer in decimal format to a string in hexadecimal format? This seems rather difficult! Here is a method that will do it:

```c++
string toHex(int input) {
	const char* alpha = "0123456789ABCDEF"; // all the digits it can have
	int r = input % 16;
	string result;
	if (input - r == 0) {
		result = alpha[r];
	} else {
		result = toHex((input - r)/16) + alpha[r];
	}
	return result;
}
```

I will not explain how this code works in depth, since you can figure it out if you read it closely. I will explain, however, that for each digit 0-15, we can go through `alpha` and the number or letter at that index will be the hex equivalent. Here is an example of using this to print a hex string, both with and without the `0x` prefix.

```c++
int main() {
	std::cout << "15 = " << toHex(15) << std::endl; // "15 = F"
	std::cout << "15 = 0x" << toHex(15) << std::endl; // "15 = 0xF"
	return 0;
}
```

**Binary in C++**

The way that you convert an integer to binary is the same as hex, in fact, it's the same as any base other than 10, which is our normal base (since it's 0-9). You just have to replace every 16 with 2, since binary is base 2, and you change your `alpha` to `"01"`. However, since it uses the same numbers, you could just leave it as `"0123456789ABCDEF"`, since it will still only use the first two.

So, here is the method that I used to convert from an integer to a binary string:

```c++
string toBin(int input) {
	const char* alpha = "01"; // all the digits it can have
	int r = input % 2;
	string result;
	if (input - r == 0) {
		result = alpha[r];
	} else {
		result = toBin((input - r)/2) + alpha[r];
	}
	return result;
}
```

Since you use this method the same way, I feel that a demonstration is not necessary, and that I won't have to show you how to use it. All you need to know is that if you try `toBin(420);` and the result is *not* `110100100`, you did something wrong.

## Converting to any base in C++

This is extremely easy to do, since you use a slightly adapted version of the previous methods we used. Here it is, and it will go all the way up to base 36.

```c++
string toBase(int input, int base) {
	const char* alpha = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int r = input % base;
	string result;
	if (input - r == 0) {
		result = alpha[r];
	} else {
		result = toBase((input - r)/base, base) + alpha[r];
	}
	return result;
}
```

Keep in mind, you will need to do some error handling in case the user puts in a base greater than 36.
