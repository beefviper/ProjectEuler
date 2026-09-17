// problem0006.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"

#include "eulerlib.h"
#include "print.h"

#include <iostream>
#include <string>
#include <cstdint>

namespace pe = ProjectEuler;

static const uint64_t number{ 6 };

static const std::string title{ "Sum square difference" };

static const std::string question{ R"(
The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 55^2 = 3025

Hence the difference between the sum of the squares of the first ten
natural numbers and the square of the sum is 3025 - 385 = 2640.

Find the difference between the sum of the squares of the first one
hundred natural numbers and the square of the sum.
)" };

namespace
{
	static uint64_t solution()
	{
		uint64_t result{ 0 };
		uint64_t limit{ 100 };

		result = pe::squareOfSums(limit) - pe::sumOfSquares(limit);

		pe::print << "The difference between the sum of the squares of the"
			<< " first one hundred natural numbers and the square of the sum is "
			<< result << "." << std::endl;

		return result;
	}

	static const std::string answer{ "The difference between the sum of the squares of the first one hundred natural numbers and the square of the sum is: {}" };

	static const pe::ProblemRegistrar problem_registrar{ number, title, question, solution, answer };
}
