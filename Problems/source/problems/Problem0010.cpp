// problem0010.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"

static const std::string title{ "Summation of primes" };

static const std::string body{ R"(
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
)" };


uint64_t problem10()
{
	uint64_t result{ 0 };
	uint64_t limit{ 2000000 };

	for (int i = 0; i < limit; i++) {
		if (checkPrime(i) == true) {
			result += i;
		}
	}

    print << "The sum of all the primes below " << limit << " is "
		<< result << "." << std::endl;

    return result;
}

static const std::optional<uint64_t> answer{ std::nullopt };

static const ProblemRegistrar problem10_registrar{ Problem{ 10, title, body, problem10, answer } };
