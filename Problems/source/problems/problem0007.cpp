// problem0007.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"
#include "print.h"
#include "eulerlib.h"

#include <string>

namespace pe = ProjectEuler;

static const pe::Number number{ 7 };

static const std::string title{ "10001st prime" };

static const std::string question{ R"(
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13,
we can see that the 6th prime is 13.

What is the 10 001st prime number?
)" };

static pe::Number solution()
{
	pe::Number result{ 0 };
	pe::Number index{ 10001 };

	result = pe::getPrimeByIndex(index);
    pe::print << "The " << index << "th prime is "
		<< result << "." << pe::endl;
	
	return result;
}

static const std::string answer{ "The 10001st prime number is: {}" };

static const pe::Number expected{ 104743 };

static const pe::ProblemRegistrar problem_registrar{ number, title, question, solution, answer, expected };
