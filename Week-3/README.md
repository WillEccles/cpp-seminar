#Week 3 Journal

This week was all about functions. I did some simple functions, covering some basic topics:

- Return types
- Input
- Void return type
- No input

My example code can be found below.

## What is a method?

A method is basically a block of code that you can run many times and can have input/return a value. For example, I could have a method called `SayHi()` that prints "hello." I could run it repeatedly and it would say hello every time.

## How do you define a method?

Every method follows this pattern:

```
[Return Type] [name]([input(s)]) {
	[code to run]
}
```

The return type is what kind of value this method returns. If it returns nothing, it should say `void`. If it returns a string, it should say `string`.

The name is pretty self explanatory.

The inputs are things that you put into the method that it works with.

Here is a method that takes in an `int` value and then returns twice that value:

```c++
int doubleThis(int input) {
	return input * 2;
}
```

In order to run this method, you have to call it from *below* the method declaration in the code, otherwise it will not have been created when you try to run it.

```c++
// method declaration
int doubleThis(int input) {
	return input * 2;
}

// call the method
int myInt = doubleThis(4); // myInt's value is now 8
```

That pretty well sums up methods. See my exmaple code for more information.

##Example Code

My example code will soon be available. Made proudly in the USA :us:
