// problem0009.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"

static const std::string title{ "Special Pythagorean triplet" };

static const std::string body{ R"(
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2

For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
)" };

static uint64_t problem()
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

    print << "a = " << resultA << ", b = " << resultB << ", c = " << resultC << std::endl;
	print << resultA << "^2 * " << resultB << "^2 = " << resultC << "^2" << std::endl;
	print << resultA << " + " << resultB << " + " << resultC << " = " << sum << std::endl;
	print << "The product of abc is " << result << "." << std::endl;

    return result;
}

static const std::optional<uint64_t> answer{ 31875000 };

static const ProblemRegistrar problem_registrar{ Problem{ 9, title, body, problem, answer } };
