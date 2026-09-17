// problem0017.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"
#include "print.h"
#include "eulerlib.h"

#include <string>

namespace pe = ProjectEuler;

static const pe::value number{ 17 };

static const std::string title{ "Number letter counts" };

static const std::string question{ R"(
If the numbers 1 to 5 are written out in words: one, two, three, four,
five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written
out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example,
342 (three hundred and forty-two) contains 23 letters
and 115 (one hundred and fifteen) contains 20 letters.
The use of "and" when writing out numbers is in compliance with British usage.
)" };

static pe::value solution()
{
	pe::value result{ 0 };
	pe::value number{ 1000 };

	//std::string words = pe::makeStringFromNumber(9999);

	for (int i = 1; i <= number; i++) {
		std::string words = pe::makeStringFromNumber(i);
        pe::print << words << pe::endl;
		result += words.length();
	}

    pe::print << "The total is " << result << "." << pe::endl;

	return result;
}

static const std::string answer{ "The total number of letters used is: {}" };

static const pe::value expected{ 21124 };

static const pe::ProblemRegistrar problem_registrar{ number, title, question, solution, answer, expected };
