// Problem0005.cpp : Defines the entry point for the console application.

/*
Problem 5: Smallest multiple

2520 is the smallest number that can be divided by each of the numbers
from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of
the numbers from 1 to 20?

Answer: 232792560
*/

#include "ProjectEuler.h"

uint64_t problem5()
{
	uint64_t result{ 0 };
	bool flag = false;

	while (flag == false) {
		result++;
		flag = isDivisibleByRange(1, 20, result);
	}
	
	//std::cout << "The smallest positive number that is evenly divisible by"
	//	<< " all of the numbers from 1 to 20 is " << result << "." << std::endl;

	return result;
}
