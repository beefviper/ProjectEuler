// problem0014.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"
#include "print.h"
#include "eulerlib.h"

#include <string>

namespace pe = ProjectEuler;

static const pe::value number{ 14 };

static const std::string title{ "Longest Collatz sequence" };

static const std::string question{ R"(
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

static pe::value solution()
{
	pe::value result{ 0 };
	pe::value num = 13;
	pe::value length = pe::collatz(num);
	pe::value max_num = 0;

  pe::print << "The chain length for " << num << " is "
		<< length << " numbers long." << pe::endl;

	for (pe::value i = 1; i <= 1000000; i++) {
		pe::value max_temp = pe::collatz(i);
		if (max_temp > result) {
			result = max_temp;
			max_num = i;
		}
        pe::print << i << ", " << max_temp << pe::endl;
	}

  pe::print << "The number with the longest chain is " << max_num
		<< " with a length of " << result << "." << pe::endl;

	return max_num;
}

static const std::string answer{ "The number with the longest chain is: {}" };

static const pe::value expected{ 837799 };

static const pe::ProblemRegistrar problem_registrar{ number, title, question, solution, answer, expected };
