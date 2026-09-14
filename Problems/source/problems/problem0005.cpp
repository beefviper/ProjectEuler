// problem0005.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"

static const std::string title{ "Smallest multiple" };

static const std::string body{ R"(
2520 is the smallest number that can be divided by each of the numbers
from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of
the numbers from 1 to 20?
)" };

static uint64_t problem()
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

static const std::optional<uint64_t> answer{ 232792560 };

static const ProblemRegistrar problem_registrar{ Problem{ 5, title, body, problem, answer } };
