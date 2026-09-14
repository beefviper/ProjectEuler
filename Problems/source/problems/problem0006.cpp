// problem0006.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"

static const std::string title{ "Sum square difference" };

static const std::string body{ R"(
The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 55^2 = 3025

Hence the difference between the sum of the squares of the first ten
natural numbers and the square of the sum is 3025 - 385 = 2640.

Find the difference between the sum of the squares of the first one
hundred natural numbers and the square of the sum.
)" };

uint64_t problem6()
{
	uint64_t result{ 0 };
	uint64_t limit{ 100 };

	result = squareOfSums(limit) - sumOfSquares(limit);

    print << "The difference between the sum of the squares of the"
		<< " first one hundred natural numbers and the square of the sum is "
		<< result << "." << std::endl;
	
	return result;
}

static const std::optional<uint64_t> answer{ 25164150 };

static const ProblemRegistrar problem6_registrar{ Problem{ 6, title, body, problem6, answer } };
