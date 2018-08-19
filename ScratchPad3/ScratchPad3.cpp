// ScratchPad3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

int main()
{
	std::string str1 = "45641436";
	std::string str2 = "63432";

	if (str1.size() > str2.size()) {
		int length = str1.size() - str2.size();
		std::string padding(length, '0');
		str2 = padding + str2;
	}
	else {
		int length = str2.size() - str1.size();
		std::string padding(length, '0');
		str1 = padding + str1;
	}

	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;
	
	system("PAUSE");
    return 0;
}

