#include "stdafx.h"
#include "myClass.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	// instantiate a myClass
	myClass mc;

	// I can ONLY run sayHi(), not actuallySayHi()
	mc.sayHi();

	system("pause");

	return 0;
}
