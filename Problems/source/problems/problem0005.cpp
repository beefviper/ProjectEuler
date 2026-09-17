// problem0005.cpp
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

static const uint64_t number{ 5 };

static const std::string title{ "Smallest multiple" };

static const std::string question{ R"(
2520 is the smallest number that can be divided by each of the numbers
from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of
the numbers from 1 to 20?
)" };

static uint64_t solution()
{
	uint64_t result{ 0 };
	bool flag = false;

	while (flag == false) {
		result++;
		flag = pe::isDivisibleByRange(1, 20, result);
	}
	
    pe::print << "The smallest positive number that is evenly divisible by"
		<< " all of the numbers from 1 to 20 is " << result << "." << std::endl;

	return result;
}

static const std::string answer{ "The smallest positive number that is evenly divisible by all of the numbers from 1 to 20 is: {}" };

static const pe::ProblemRegistrar problem_registrar{ number, title, question, solution, answer };
