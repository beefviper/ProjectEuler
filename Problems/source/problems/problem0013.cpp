// problem0013.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"

static const std::string title{ "Large sum" };

static const std::string body{ R"(
Work out the first ten digits of the sum of the following
one-hundred 50-digit numbers.
)" };

uint64_t problem13()
{
	uint64_t result{ 0 };
	std::string numbersFileName = "data/numbers.txt";
	std::vector<std::string> numbers = loadNumbers(numbersFileName);
	std::string total(50, '0');
	
	for (auto& number : numbers) {
        print << number << std::endl;
		total = addLargeNumbers(total, number);
	}

    print << "The total is " << total << "." << std::endl;

	//result = std::stol(total);

	return result;
}

static const std::optional<uint64_t> answer{ 5537376230 };

static const ProblemRegistrar problem13_registrar{ Problem{ 13, title, body, problem13, answer } };
