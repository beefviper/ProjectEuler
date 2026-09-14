// problem0007.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "Problems.h"

/*
Problem 7: 10001st prime

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13,
we can see that the 6th prime is 13.

What is the 10 001st prime number?

Answer: 104743
*/


uint64_t problem7()
{
	uint64_t result{ 0 };
	uint64_t index{ 10001 };

	result = getPrimeByIndex(index);
	//std::cout << "The " << index << "th prime is "
	//	<< result << "." << std::endl;
	
	return result;
}

static const ProblemRegistrar problem7_registrar{ Problem{ 7, problem7, 104743 } };
