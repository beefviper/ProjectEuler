// Problem0016.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
Problem 16: Power digit sum

2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?

Answer: 1366
*/

#include "stdafx.h"

int problem16() {
	
	std::string numberOne = "654646846453489";
	std::string numberTwo = "546546468415312";
	std::string largeNumber = multipleLargeNumbers(numberOne, numberTwo);

	std::cout << "numberOne = " << numberOne << std::endl;
	std::cout << "numberTwo = " << numberTwo << std::endl;
	std::cout << "largeNumber = " << largeNumber << std::endl;
	
	std::string total = "1";

	for (int i = 0; i < 1000; i++) {
		total = multipleLargeNumbers(total, "2");
	}

	int answer = 0;
	for (char c : total) {
		answer = answer + atoi(&c);
	}

	std::cout << "The sum is " << answer << std::endl;

	system("PAUSE");
	return 0;
}
