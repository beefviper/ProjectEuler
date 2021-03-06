// Problem0005.cpp : Defines the entry point for the console application.

/*
Problem 5: Smallest multiple

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

Answer: 232792560
*/

#include "stdafx.h"

int problem5()
{
	bool result = false;
	int number = 0;

	while (result == false) {
		number++;
		result = isDivisibleByRange(1, 20, number);
	}

	std::cout << "The smallest positive number that is evenly divisible by all of the numbers from 1 to 20 is " << number << "." << std::endl;

	system("PAUSE");
	return 0;
}
