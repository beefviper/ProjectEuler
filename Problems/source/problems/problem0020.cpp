// problem0020.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"

#include "eulerlib.h"
#include "print.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstdint>

namespace pe = ProjectEuler;

static const uint64_t number{ 20 };

static const std::string title{ "Factorial digit sum" };

static const std::string question{ R"(
n! means n x (n - 1) x ... x 3 x 2 x 1

For example, 10! = 10 x 9 x ... x 3 x 2 x 1 = 3628800,
and the sum of the digits in the number 10! is
3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
)" };

static uint64_t solution()
{
	uint64_t result{ 0 };
	uint64_t number{ 100 };
	std::string answer = "1";

	for (int i = 1; i <= number; i++) {
		answer = pe::multipleLargeNumbers(answer, std::to_string(i));
	}

    pe::print << "The factorial of " << number << " is "
		<< answer << std::endl;

	for (char c : answer) {
		result += atoi(&c);
	}

    pe::print << "The sum of all the digits is " << result << std::endl;

	return result;
}

static const std::string answer{ "The sum of the digits in the number 100! is: {}" };

static const pe::ProblemRegistrar problem_registrar{ number, title, question, solution, answer };
