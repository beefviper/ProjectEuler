// Problem0014.cpp : Defines the entry point for the console application.

/*
Problem 14: Longest Collatz sequence

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1)
contains 10 terms. Although it has not been proved yet (Collatz Problem),
it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

Answer: 837799
*/

#include "ProjectEuler.h"

uint64_t problem14()
{
	uint64_t result{ 0 };
	int num = 13;
	int length = collatz(num);
	int max_num = 0;

//	std::cout << "The chain length for " << num << " is "
//		<< length << " numbers long." << std::endl;

	for (int i = 1; i <= 1000000; i++) {
		int max_temp = collatz(i);
		if (max_temp > result) {
			result = max_temp;
			max_num = i;
		}
		//std::cout << i << ", " << max_temp << std::endl;
	}

//	std::cout << "The number with the longest chain is " << max_num
//		<< " with a length of " << result << "." << std::endl;

	return result;
}
