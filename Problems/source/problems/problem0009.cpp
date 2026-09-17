// problem0009.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"

#include "print.h"

#include <iostream>
#include <string>
#include <cstdint>

namespace pe = ProjectEuler;

static const uint64_t number{ 9 };

static const std::string title{ "Special Pythagorean triplet" };

static const std::string question{ R"(
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2

For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
)" };

static uint64_t solution()
{
	uint64_t result{ 0 };

	uint64_t resultA = 0;
	uint64_t resultB = 0;
	uint64_t resultC = 0;

	for (int a = 1; a < 1000; a++) {
		for (int b = 1; b < 1000; b++) {
			for (int c = 1; c < 1000; c++) {
				if (a + b + c == 1000) {
					if (a*a + b * b == c * c) {
						resultA = a;
						resultB = b;
						resultC = c;
					}
				}
			}
		}
	}

	uint64_t sum = resultA + resultB + resultC;
	result = resultA * resultB * resultC;

    pe::print << "a = " << resultA << ", b = " << resultB << ", c = " << resultC << std::endl;
	pe::print << resultA << "^2 * " << resultB << "^2 = " << resultC << "^2" << std::endl;
	pe::print << resultA << " + " << resultB << " + " << resultC << " = " << sum << std::endl;
	pe::print << "The product of abc is " << result << "." << std::endl;

    return result;
}

static const std::string answer{ "The product of abc is: {}" };

static const pe::ProblemRegistrar problem_registrar{ number, title, question, solution, answer };
