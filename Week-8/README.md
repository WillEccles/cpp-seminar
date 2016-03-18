# Week 8 - Loops

This week is all about loops, which means that all of this information is redundant from other languages.

## For Loops

The format of a for loop is this: `for ( init; condition; increment ) { ... }`

Here is how this works: It starts looking at `init`. It then checks to see if `condition` is true or false. If true, it runs the code in the block and *then* does `increment`. This sounds very confusing, let me use an example.

```c++
for (int i = 1; i <= 25; i++) {
	std::cout << i << std::endl;
}
```

First, we define `init`, an `int` named `i`. This starts at 1. Since `i` is less than or equal to (`<=`) 25, it will do the code in the block, printing `1` to the console. Then, it will do `i++`, setting `i` to 2. Since this is less than or equal to 25, it will print it... And it will do this 25 times.

Here is the output from that:

```
1
2
3
4
5
6
...
25
```

I'm sure you can do the math in your head to find out what should be there instead of `...`, but I didn't want to type all that.

## While Loops

A while loop is the most simple kind. There are two ways to write it:

```c++
// method 1
while ( /*condition*/ ) {
	// do this
}

// method 2
do {
	// do this
} while ( /*condition*/ );
```

These two loops are *almost* identicle in function: While `condition` is true, do the stuff in the block. The only difference is that in the `do {} while ()` loop, it will run once and then run again IF the condition is met. In other words, it runs at least once.

Here is an example, using the same kind of counting as before.

```c++
int i = 1;

while (i <= 25) {
	std::cout << i << std::endl;
	i++;
}
```

Once again, this will print all the numbers 1 through 25. Here is an example of how to use a do/while loop:

```c++
int i = 26;

do {
	std::cout << i << std::endl;
	i++;
} while (i <= 25);
```

In this one, it will print the 26 and then stop, since `i` is NOT less than or equal to 25.

## Example Code

Here is my example code, made in the USA. :us:

