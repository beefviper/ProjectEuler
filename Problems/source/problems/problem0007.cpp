// problem0007.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"

static const uint64_t number{ 7 };

static const std::string title{ "10001st prime" };

static const std::string body{ R"(
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13,
we can see that the 6th prime is 13.

What is the 10 001st prime number?
)" };

static uint64_t problem()
{
	uint64_t result{ 0 };
	uint64_t index{ 10001 };

	result = getPrimeByIndex(index);
    print << "The " << index << "th prime is "
		<< result << "." << std::endl;
	
	return result;
}

static const std::optional<uint64_t> answer{ 104743 };

static const ProblemRegistrar problem_registrar{ Problem{ number, title, body, problem, answer } };
