// problem0010.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"
#include "print.h"
#include "eulerlib.h"

#include <string>

namespace pe = ProjectEuler;

static const pe::Number number{ 10 };

static const std::string title{ "Summation of primes" };

static const std::string question{ R"(
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
)" };

static pe::Number solution()
{
	pe::Number result{ 0 };
	pe::Number limit{ 2000000 };

	for (int i = 0; i < limit; i++) {
		if (pe::checkPrime(i) == true) {
			result += i;
		}
	}

    pe::print << "The sum of all the primes below " << limit << " is "
		<< result << "." << pe::endl;

    return result;
}

static const std::string answer{ "The sum of all the primes below two million is: {}" };

static const pe::Number expected{ 142913828922 };

static const pe::ProblemRegistrar problem_registrar{ number, title, question, solution, answer, expected };
