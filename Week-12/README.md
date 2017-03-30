# Week 12: Pointers

This week, I will do my best to explain a fairly difficult/complicated/confusing C feature called pointers. These are useful, and can be used in a lot of ways.

**If this explanation is not good enough, I recommend reading [this one](http://www.cplusplus.com/doc/tutorial/pointers/).**

## What is a pointer?

A pointer is a type of variable, in a way. Instead of saying to the computer, "Hey! I'm an int! My value is 42!" it says, "Hey! Look over there! That's an int!" Okay, so maybe it's not a "type of variable," per se, but it's percieved as one in your mind, probably. They're called pointers because they point to the address of a variable in memory. I'll explain that below.

This is confusing, since usually you are used to just setting a value directly. Here is how you define a pointer and a non-pointer:

```c++
// non-pointer
int nonpointer = 42;
// pointer
int *ispointer = &nonpointer; // value is still 42
```

So what are the `*` and `&` operators?

### Address-of Operator (`&`)
`&` is called the address-of operator. This is because it literally returns the address of the variable in front of it. The address in question is just where the value of that variable is stored in memory. This is a number, since it's an index, a location in the memory. For example, if I do `foo = 46` and it stores the 46 at address 0xFF (since addresses are in hexadecimal), or 255, and then print `&foo`, it would print 255. Well, it would actually print `ff` most likely, but you get the point. This is useful since you can change a value at a memory location, meaning you can change it directly from places you didn't think it could.

```c++
// make a number in main
int main() {
	int mynum = 12;
	double(mynum);
	cout << mynum << endl;
	// this will print 24 to the console
}

// pretend this is usable from main, even though it's defined after	
void double(int a) {
	// this will set the value of mynum to (2 * mynum) when I use it
	&a = 2 * a;
	// "go to the address of a and directly change it to 2 times a"
}
```

So this is one way to use it. But since this is about pointers, how can I use it with those? We'll get to that later.

### Dereference Operator (`*`)
`*` is called the dereference operator. This is used to make a pointer to a type. I wrote it as `[typename] *[varname]`, but you can put it anywhere between those two things:

```c++
// these all work the same
int *thing;
int * thing;
int* thing;
int    *thing;
int            *                thing;
```

You can read this operator as "the value pointed to by" since it can be used to read the value pointed to by the given memory address. For example, if I have a variable called `foo` and I set it to 46 (`foo = 46`), then I can get its address using the `&` operator. In the following example, assume that the memory address (location in memory) of `foo`'s value is 1000.

```c++
foo = 46;
address = &foo; // (address of foo = 1000)
bar = *address; // "bar = the value pointed to by address"
```

This is how the dereference operator works.

## So how do you use these things?

Well, pointers are used a lot to manage memory, especially in C, since you can directly modify the memory by address.

Another way is to make a string literal. For example, in C and C++, you define a string in one of two ways:

```c++
// number 1:
char mystring[] = "hello";
// number 2:
char * mystring = "hello";
```

How come the pointer to a char works the same as an array of them? This is somewhat hard to explain, but here we go:

Think of each `[]` as a single spot in memory. The number above it is the address of the box, and the number in it is, well, the value at that address. `'\0'` is a special character called the null-terminator. This is automatically added at the end of a string to tell the computer to stop reading the string there. Thus, when defining a string like `char thing[6] = "hello"`, you should set the length (`6` here) to n+1, where n is the length of the string. If you don't, there will be problems, since it has nowhere to store the null character.

```
 1000   1001   1002   1003   1004   1005
[ 'h' ][ 'e' ][ 'l' ][ 'l' ][ 'o' ][ '\0' ]
```

Using the `char*` sets the value of `mystring` to the first address of the letters, so `mystring` is not `"hello"` or `'h'`, it's value is `1000`. To access the first letter of `mystring`, you'd usually do this:

```c++
mystring[0] // h
```

This is exactly the same as doing this:

```c++
*(mystring) // h
```

Why are these the same? Another example may help you with that:

```c++
mystring[4] // o
*(mystring+4) // o
```

So why does this work, again? The first one says to grab the 5th element of the array. It does. But the second one looks kinda funny... See, the value of `mystring` is the address of the first element, which in this example is 1000. So in the parentheses, I use `mystring + 4`, which would be 1004. Then I use the dereference operator, `*`, to say, "the value at the address (1004)," which would be 'o'.

## A more complex example:

Say we have a class that contains a string and has a method to update it:

```c++
class strClass {
	std::string myStr;
	public:
		strClass(std::string s): myStr(s) {}
		void setStr(std::string s) {myStr = s;}
		std::string getStr() {return myStr;}
};
```

Now, say we have another class which contains a pointer to a `strClass`, and updates the `string` in the instance it's pointing to:

```c++
class updater {
	strClass *sClass;
	public:
		updater(strClass &sC) {sClass = &sC;}
		void updateStr(std::string newStr) {sClass->setStr(newStr);}
};
```

Note that I used a `->` instead of a `.` to access the `setStr` method in `sClass`. This is because you have to use this operator to access the parts of a pointer instead of a period. It's just how it is.

Now here is our main:

```c++
int main(void) {
	strClass s(std::string("this is my string"));
	std::cout << s.getStr() << std::endl; // prints "this is my string"
	updater u(s);
	u.updateStr(std::string("this is my new string"));
	std::cout << s.getStr() << std::endl; // prints "this is my new string"

	return 0;
}
```

Notice how `u` contains a pointer to `s`, and so setting the pointer's string directly updates `s`'s. This is because `u` contains a reference to `s`, even though it's defined elsewhere. Interesting, eh?

# Example code
My example code can be found [here](code/main.cpp). Made in the USA. :us:
