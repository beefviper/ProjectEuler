// problem0003.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"

#include "eulerlib.h"
#include "print.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

namespace pe = ProjectEuler;

static const uint64_t number{ 3 };

static const std::string title{ "Largest prime factor" };

static const std::string question{ R"(
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
)" };

static uint64_t solution()
{
	uint64_t result{ 0 };
	uint64_t numberToFactor{ 600851475143 };
	std::vector<uint64_t> factors = pe::primeFactors(numberToFactor);

    pe::print << "The prime factors of " << numberToFactor << " is ";
	for (uint64_t factor : factors) {
        pe::print << factor << ", ";
	}
    pe::print << std::endl;

	if (!factors.empty()) {
		result = factors.back();
        pe::print << "The largest prime factor of " << numberToFactor << " is "
			<< result << std::endl;
	}
	else {
        pe::print << "There are no prime factors." << std::endl;
	}

    return result;
}

static const std::string answer{ "The largest prime factor is: {}" };

static const pe::ProblemRegistrar problem_registrar{ number, title, question, solution, answer };
