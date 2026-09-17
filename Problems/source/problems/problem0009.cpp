// problem0009.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"
#include "print.h"

#include <string>

namespace pe = ProjectEuler;

static const pe::Number number{ 9 };

static const std::string title{ "Special Pythagorean triplet" };

static const std::string question{ R"(
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2

For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
)" };

static pe::Number solution()
{
	pe::Number result{ 0 };

	pe::Number resultA = 0;
	pe::Number resultB = 0;
	pe::Number resultC = 0;

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

	pe::Number sum = resultA + resultB + resultC;
	result = resultA * resultB * resultC;

    pe::print << "a = " << resultA << ", b = " << resultB << ", c = " << resultC << pe::endl;
	pe::print << resultA << "^2 * " << resultB << "^2 = " << resultC << "^2" << pe::endl;
	pe::print << resultA << " + " << resultB << " + " << resultC << " = " << sum << pe::endl;
	pe::print << "The product of abc is " << result << "." << pe::endl;

    return result;
}

static const std::string answer{ "The product of abc is: {}" };

static const pe::Number expected{ 31875000 };

static const pe::ProblemRegistrar problem_registrar{ number, title, question, solution, answer, expected };
