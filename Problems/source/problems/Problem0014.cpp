// problem0014.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "Problems.h"

/*
Problem 14: Longest Collatz sequence

The following iterative sequence is defined for the set of positive integers:

n â†’ n/2 (n is even)
n â†’ 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 â†’ 40 â†’ 20 â†’ 10 â†’ 5 â†’ 16 â†’ 8 â†’ 4 â†’ 2 â†’ 1

It can be seen that this sequence (starting at 13 and finishing at 1)
contains 10 terms. Although it has not been proved yet (Collatz Problem),
it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

Answer: 837799
*/


uint64_t problem14()
{
	uint64_t result{ 0 };
	uint64_t num = 13;
	uint64_t length = collatz(num);
	uint64_t max_num = 0;

//	std::cout << "The chain length for " << num << " is "
//		<< length << " numbers long." << std::endl;

	for (uint64_t i = 1; i <= 1000000; i++) {
		uint64_t max_temp = collatz(i);
		if (max_temp > result) {
			result = max_temp;
			max_num = i;
		}
		//std::cout << i << ", " << max_temp << std::endl;
	}

//	std::cout << "The number with the longest chain is " << max_num
//		<< " with a length of " << result << "." << std::endl;

	return max_num;
}

static const ProblemRegistrar problem14_registrar{ Problem{ 14, problem14, 837799 } };

