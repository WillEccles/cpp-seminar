#include "StdAfx.h"
#include "myClass.h"
#include <iostream>
#include <string>

// this shows that myClass contains the member sayHi(), as the header said.
// see the README.md file in this week's journal to learn about that.
void myClass::sayHi() {
	actuallySayHi();
}

// this method is below the other, but the other one calls it and it works just fine.
// before, I said that this does not work. However, there is a trick:
// headers act kind of as an index. sayHi() (above) will look in myClass.h and see this method
// it will then be able to use it, since the header instantiates this before this class does
void myClass::actuallySayHi() {
	std::cout << "Hello." << std::endl;
}
