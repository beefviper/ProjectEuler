// problem0005.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"
#include "print.h"
#include "eulerlib.h"

#include <string>

namespace pe = ProjectEuler;

static const pe::Number number{ 5 };

static const std::string title{ "Smallest multiple" };

static const std::string question{ R"(
2520 is the smallest number that can be divided by each of the numbers
from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of
the numbers from 1 to 20?
)" };

static pe::Number solution()
{
	pe::Number result{ 0 };
	bool flag = false;

	while (flag == false) {
		result++;
		flag = pe::isDivisibleByRange(1, 20, result);
	}
	
    pe::print << "The smallest positive number that is evenly divisible by"
		<< " all of the numbers from 1 to 20 is " << result << "." << pe::endl;

	return result;
}

static const std::string answer{ "The smallest positive number that is evenly divisible by all of the numbers from 1 to 20 is: {}" };

static const pe::Number expected{ 232792560 };

static const pe::ProblemRegistrar problem_registrar{ number, title, question, solution, answer, expected };
