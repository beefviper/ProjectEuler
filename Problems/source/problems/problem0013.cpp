// problem0013.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"
#include "print.h"
#include "eulerlib.h"

#include <string>
#include <vector>

namespace pe = ProjectEuler;

static const pe::value number{ 13 };

static const std::string title{ "Large sum" };

static const std::string question{ R"(
Work out the first ten digits of the sum of the following
one-hundred 50-digit numbers.
)" };

static pe::value solution()
{
	pe::value result{ 0 };
	std::string numbersFileName = "data/numbers.txt";
	std::vector<std::string> numbers = pe::loadNumbers(numbersFileName);
	std::string total(50, '0');
	
	for (auto& number : numbers) {
        pe::print << number << pe::endl;
		total = pe::addLargeNumbers(total, number);
	}

    pe::print << "The total is " << total << "." << pe::endl;

	return result;
}

static const std::string answer{ "The first ten digits of the sum of the one-hundred 50-digit numbers is: {}" };

static const pe::value expected{ 5537376230 };

static const pe::ProblemRegistrar problem_registrar{ number, title, question, solution, answer, expected };
