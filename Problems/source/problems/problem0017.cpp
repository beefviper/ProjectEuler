// problem0017.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"

#include "eulerlib.h"
#include "print.h"

#include <iostream>
#include <optional>
#include <string>

namespace pe = ProjectEuler;

static const uint64_t number{ 17 };

static const std::string title{ "Number letter counts" };

static const std::string body{ R"(
If the numbers 1 to 5 are written out in words: one, two, three, four,
five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written
out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example,
342 (three hundred and forty-two) contains 23 letters
and 115 (one hundred and fifteen) contains 20 letters.
The use of "and" when writing out numbers is in compliance with British usage.
)" };

static uint64_t problem()
{
	uint64_t result{ 0 };
	uint64_t number{ 1000 };

	//std::string words = pe::makeStringFromNumber(9999);

	for (int i = 1; i <= number; i++) {
		std::string words = pe::makeStringFromNumber(i);
        pe::print << words << std::endl;
		result += words.length();
	}

    pe::print << "The total is " << result << "." << std::endl;

	return result;
}

static const std::optional<uint64_t> answer{ 21124 };

static const pe::ProblemRegistrar problem_registrar{ number, title, body, problem, answer };
