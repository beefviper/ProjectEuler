// problem0003.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"

static const std::string title{ "Largest prime factor" };

static const std::string body{ R"(
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
)" };

static uint64_t problem()
{
	uint64_t result{ 0 };
	uint64_t numberToFactor{ 600851475143 };
	std::vector<uint64_t> factors = primeFactors(numberToFactor);

    print << "The prime factors of " << numberToFactor << " is ";
	for (uint64_t factor : factors) {
        print << factor << ", ";
	}
    print << std::endl;

	if (!factors.empty()) {
		result = factors.back();
        print << "The largest prime factor of " << numberToFactor << " is "
			<< result << std::endl;
	}
	else {
        print << "There are no prime factors." << std::endl;
	}

    return result;
}

static const std::optional<uint64_t> answer{ 6857 };

static const ProblemRegistrar problem_registrar{ Problem{ 3, title, body, problem, answer } };
