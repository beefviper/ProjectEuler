// problem0010.cpp
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

static const uint64_t number{ 10 };

static const std::string title{ "Summation of primes" };

static const std::string question{ R"(
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
)" };

static uint64_t solution()
{
	uint64_t result{ 0 };
	uint64_t limit{ 2000000 };

	for (int i = 0; i < limit; i++) {
		if (pe::checkPrime(i) == true) {
			result += i;
		}
	}

    pe::print << "The sum of all the primes below " << limit << " is "
		<< result << "." << std::endl;

    return result;
}

static const std::string answer{ "The sum of all the primes below two million is: {}" };

static const pe::ProblemRegistrar problem_registrar{ number, title, question, solution, answer };
