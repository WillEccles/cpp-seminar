# Week 17 - Templates

This week, I will discuss templates, which are a handy way of reducing overloads on methods. They can make debugging a little more difficult, however.

## What is a template?

A template is a useful tool that allows you to overload a method without *actually* overloading it. First of all, what is overloading? Overloading is where you have multiple of the same method, but with different arguments/return types, so that you can use the same method with multiple types of things, different arguments, and so on.

A template removes this need, since you can write one piece of code that will apply to many situations. Let's look at a quick example of overloading, which we will fix using a template:

```c++
// get the largest of two ints
int max(int a, int b) {
	return (a > b ? a : b);
}

// get the max of two longs
long max(long a, long b) {
	return (a > b ? a : b);
}
```

As you can see, the methods use the same code, they just have different input types. This means that if I use `max((long)12, (long)13)`, it will return `(long)13`, but if I do the same using ints, it will return `(int)13`. It will use different methods, they just look the same to us. So how can we solve this problem?

## How to make a template

First, let's look at an example of a template that already exists. The `std::vector` is a template class, meaning that it's a class where we have to specify a type for it to us, like when we do `vector<int> mynumbers;`. In this case, we selected `int` as the type that we want it to hold. In this case, we will talk about template methods, but they work the same way. Here is how to replace the above methods with a template:

```c++
template<class NumberType>
NumberType max(NumberType a, NumberType b) {
	return (a > b ? a : b);
}
```

This method works in a strange way. You may be thinking, "What is a NumberType? I have never seen that before!" True, because it's just the name of the variable. The things inside the `<>` are just like those inside of the `()` of a method: they are just arguments. In this case, we only have one, and it's of type `class`. This means that we can specify a class to use, and it will be in scope within this entire method. Notice that `template<>` is on the top of the method. This is not necessary, you can write it as `template<x> x max(x a, x b)`, but if you put the `template` above it the method it keeps it cleaner.

So when you run this method, you can do it in one of two ways:

```c++
int main() {
	int first = 12;
	int second = 13;
	
	int most = max<int>(first, second);
	int alsoMost = max(first, second);
	
	return 0;
}
```

So why the difference? What does it mean? Well, in the first example we put in `<int>` manually. This specifically tells the compiler to look for two `int` inputs and to return an `int`. The second time, we didn't do that. So why does the second one work? As long as it's not ambiguous, the compiler can assume which type you meant to put in there, since it can look at your arguments and see that both of them are of type `int`.

We can use this method for different types of numbers. Here are some examples, where I use that method for types `long`, `int`, and `double`. I could also use a `char`, along with many other types, since a lot of them boil down to integer values in C++.

```c++
long maxlong = max((long)12, (long)13);
int maxint = max((int)12, (int)13);
double maxdouble = max((double)12.5, (double)13.5);
```

*Note: I could have defined two longs, two ints, and two doubles instead of simply casting, but that would have taken more space.*

## More advanced templates

Templates can also have multiple types of classes/typenames specified, which gives them a whole lot of power. Look at this example:

```c++
template<class Type1, class Type2>
void printBoth(Type1 thing1, Type2 thing2) {
	cout << thing1 << endl << thing2 << endl;
}
```

As you can see, I want two different types. These can be the same type, but if they aren't, this will still handle it.

<sup>Made proudly in the USA. :us:</sup>