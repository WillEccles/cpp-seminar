# Week 18 - Kata04 Challenge

This week, I looked at a simple challenge, which was [the Kata #04 challenge](http://codekata.com/kata/kata04-data-munging/). The goal was to look at a file which had multiple columns of data and print the day number with the largest variation in temperature.

The input can be found on that page. I will only be doing Part One, so I will only be using `weather.dat`.

## Initial Thought

So first of all, if you look at the input, you can see that there is a title row, a blank row, and a "mo" row (for the whole month) at the end. I just want the 30 days that are in between, and the first three columns (day number, max, and min temperatures) of them are the only useful ones. First of all, in order to get a working base program, I removed everything except for those and also removed the asterisks that were on a couple of days' temperatures. Keep in mind, I have to fix this later on. But first off, here is what I end up with. Using this custom input and such, it gets the right answer ridiculously fast.

```c++
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	fstream file("weather.dat");
	int day, max, min;

	vector<int> ranges;

	while (file >> day >> max >> min)
		ranges.push_back(max - min);

	int indexOfMax = distance(ranges.begin(), min_element(ranges.begin(), ranges.end()));

	cout << "Day with smallest variation: " << indexOfMax + 1 << endl;

	system("pause");
	return 0;
}
```

This code works just right. However, what happens when I put the other input back in? I would explain this here, but the problem is that we have Visual Studio 2010 - which doesn't support C++11, and therefore makes all of this work much harder. **Let it be known, however, that you definitely can just use C++ to do this with unmodified input.**

Realistically, however, I would just use Excel to do this.
