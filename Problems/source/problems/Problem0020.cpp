// problem0020.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"

// Problem0020.cpp : This file contains the 'main' function.

/*
Problem 20: Factorial digit sum

n! means n Ã— (n âˆ’ 1) Ã— ... Ã— 3 Ã— 2 Ã— 1

For example, 10! = 10 Ã— 9 Ã— ... Ã— 3 Ã— 2 Ã— 1 = 3628800,
and the sum of the digits in the number 10! is
3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!

Answer: 648
*/


uint64_t problem20()
{
	uint64_t result{ 0 };
	uint64_t number{ 100 };
	std::string answer = "1";

	for (int i = 1; i <= number; i++) {
		answer = multipleLargeNumbers(answer, std::to_string(i));
	}

    print << "The factorial of " << number << " is "
		<< answer << std::endl;

	for (char c : answer) {
		result += atoi(&c);
	}

    print << "The sum of all the digits is " << result << std::endl;

	return result;
}

static const ProblemRegistrar problem20_registrar{ Problem{ 20, problem20, 648 } };
