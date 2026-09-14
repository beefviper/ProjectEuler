// problem0001.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "Problems.h"

/*
Problem 1: Multiples of 3 and 5

If we list all the natural numbers below 10 that are multiples of 3 or 5,
we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

Answer: 233168
*/


uint64_t problem1()
{
	uint64_t result{ 0 };

	for (int i = 0; i < 1000; i++) {
		if ((i % 3 == 0) || (i % 5 == 0)) {
			result += i;
		}
	}

    print << "The sum is: " << result << std::endl;
	
    return result;
}

static const ProblemRegistrar problem1_registrar{ Problem{ 1, problem1, 233168 } };
