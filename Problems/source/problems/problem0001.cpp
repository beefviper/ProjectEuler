// problem0001.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"
#include "print.h"

#include <string>

namespace pe = ProjectEuler;

static const pe::value number{ 1 };

static const std::string title{ "Multiples of 3 and 5" };

static const std::string question{ R"(
If we list all the natural numbers below 10 that are multiples of 3 or 5,
we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
)" };

static pe::value solution()
{
	pe::value result{ 0 };

	pe::print << "Finding factors of 3 or 5 below 1000..." << pe::endl;

	for (int i = 0; i < 1000; i++) {
		if ((i % 3 == 0) || (i % 5 == 0)) {
			result += i;
			
			//pe::print << i << "(" << result << ")";
		}
	}

	pe::print << pe::endl;

    return result;
}

static const std::string answer{ "The sum is: {}" };

static const pe::value expected{ 233168 };

static const pe::ProblemRegistrar problem_registrar{ number, title, question, solution, answer, expected };
