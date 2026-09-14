// problem0014.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"

static const std::string title{ "Longest Collatz sequence" };

static const std::string body{ R"(
The following iterative sequence is defined for the set of positive integers:

n -> n/2 (n is even)
n -> 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1

It can be seen that this sequence (starting at 13 and finishing at 1)
contains 10 terms. Although it has not been proved yet (Collatz Problem),
it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
)" };


uint64_t problem14()
{
	uint64_t result{ 0 };
	uint64_t num = 13;
	uint64_t length = collatz(num);
	uint64_t max_num = 0;

  print << "The chain length for " << num << " is "
		<< length << " numbers long." << std::endl;

	for (uint64_t i = 1; i <= 1000000; i++) {
		uint64_t max_temp = collatz(i);
		if (max_temp > result) {
			result = max_temp;
			max_num = i;
		}
        print << i << ", " << max_temp << std::endl;
	}

  print << "The number with the longest chain is " << max_num
		<< " with a length of " << result << "." << std::endl;

	return max_num;
}

static const std::optional<uint64_t> answer{ 837799 };

static const ProblemRegistrar problem14_registrar{ Problem{ 14, title, body, problem14, answer } };
