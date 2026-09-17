// problem0013.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"

#include "eulerlib.h"
#include "print.h"

#include <iostream>
#include <optional>
#include <string>
#include <vector>

namespace pe = ProjectEuler;

static const uint64_t number{ 13 };

static const std::string title{ "Large sum" };

static const std::string body{ R"(
Work out the first ten digits of the sum of the following
one-hundred 50-digit numbers.
)" };

static uint64_t problem()
{
	uint64_t result{ 0 };
	std::string numbersFileName = "data/numbers.txt";
	std::vector<std::string> numbers = pe::loadNumbers(numbersFileName);
	std::string total(50, '0');
	
	for (auto& number : numbers) {
        pe::print << number << std::endl;
		total = pe::addLargeNumbers(total, number);
	}

    pe::print << "The total is " << total << "." << std::endl;

	//result = std::stol(total);

	return result;
}

static const std::optional<uint64_t> answer{ 5537376230 };

static const pe::ProblemRegistrar problem_registrar{ number, title, body, problem, answer };
