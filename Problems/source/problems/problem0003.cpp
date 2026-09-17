// problem0003.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"
#include "print.h"
#include "eulerlib.h"

#include <string>
#include <vector>

namespace pe = ProjectEuler;

static const pe::value number{ 3 };

static const std::string title{ "Largest prime factor" };

static const std::string question{ R"(
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
)" };

static pe::value solution()
{
	pe::value result{ 0 };
	pe::value numberToFactor{ 600851475143 };
	std::vector<pe::value> factors = pe::primeFactors(numberToFactor);

    pe::print << "The prime factors of " << numberToFactor << " is ";
	for (pe::value factor : factors) {
        pe::print << factor << ", ";
	}
    pe::print << pe::endl;

	if (!factors.empty()) {
		result = factors.back();
        pe::print << "The largest prime factor of " << numberToFactor << " is "
			<< result << pe::endl;
	}
	else {
        pe::print << "There are no prime factors." << pe::endl;
	}

    return result;
}

static const std::string answer{ "The largest prime factor is: {}" };

static const pe::value expected{ 6857 };

static const pe::ProblemRegistrar problem_registrar{ number, title, question, solution, answer, expected };
