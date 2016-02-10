# Week 4 Journal

This is being written a week early, but I got bored.

This was all about headers. I also mention scope in this journal.

## What is a header?

A header file (`filename.h`) is a part of a class. It defines members of the class that it is part of. These members (methods, variables, etc.) can either be private or public. This is where scope comes into play.

A class is usually two parts: `classname.cpp` and `classname.h`.

A header can be defined that isn't corresponding to a class, and can be inherited by any other class. You can just make definitions (as in pre-processor definitions) which will be used by all classes inheriting it.

If a header corresponds to a class, it will tell any class that inherits it what methods and members it can and can't access inside that class. When you define something in a header, you must then create the actual code inside that class that defines each member.

Example class and header (I have removed the includes and such).

```c++
// exampleClass.h

class exampleClass {
public:
	// public method
	void myMethod();
private:
	// private method
	void privateMethod();
}
```

```c++
// exampleClass.cpp

// this must have the exampleClass:: to show that it is in this class according to the header
void exampleClass::myMethod() { }

// this one is private
void exampleClass::privateMethod() { }
```

When you instantiate the exampleClass in some other class (after doing `#include "exampleClass.h"`), it will use this header to determine which methods and members exist.

This means that you no longer have to define a method above another one if you want to use it in the other method. Since they now both exist, they can be used in any order.

## Example code

My example code can be found [here](https://github.com/WillEccles/cpp-seminar/tree/master/Week-4/Code). Proudly made in the USA. :us:
