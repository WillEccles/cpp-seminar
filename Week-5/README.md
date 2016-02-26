# Week 5 Journal

This week will be all about casting. There's not that much to say about this in C++.

## What is casting?

Casting is a way to tell the compiler to treat one thing of one type as another type. Basically, let's say we have a float, 1.5, for example. We want to store this value in an integer. To do this, I can do the following:

```c++
float startingFloat = 1.5;
int myInt = (int) startingFloat;
```

Here, writing `(int)` says to the compiler, "Hey, I know this is a float, but you should pretend it's an integer.

This example is one where you will experience a pretty good amount of data lost. Since the integer value can't contain a decimal, your integer will be set to 1.

## Implicit Casting

Above, I described explicit casting, where I explicitly told the compiler which type to convert to the other. However, in C++ (and many other languages), you can cast implicitly - that is, you can do it without specifying a type.

This can only be done between compatible types - for example, a `short` and an `int`. I can define a `short` and then store it in an `int`, and no error will arise.

```c++
short A = 12;
int B = A;
```

This code will cause no errors, since the types `int` and `short` are compatible with each other.

## Example Code

My example code can be found [here](https://github.com/WillEccles/cpp-seminar/blob/master/Week-5/Code/main.cpp). Made proudly in the USA. :us:
