// problem0005.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "Problems.h"

/*
Problem 5: Smallest multiple

2520 is the smallest number that can be divided by each of the numbers
from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of
the numbers from 1 to 20?

Answer: 232792560
*/


uint64_t problem5()
{
	uint64_t result{ 0 };
	bool flag = false;

	while (flag == false) {
		result++;
		flag = isDivisibleByRange(1, 20, result);
	}
	
    print << "The smallest positive number that is evenly divisible by"
		<< " all of the numbers from 1 to 20 is " << result << "." << std::endl;

	return result;
}

static const ProblemRegistrar problem5_registrar{ Problem{ 5, problem5, 232792560 } };
