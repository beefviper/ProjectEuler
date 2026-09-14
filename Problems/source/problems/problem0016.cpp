// problem0016.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"

static const std::string title{ "Power digit sum" };

static const std::string body{ R"(
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
)" };

static uint64_t problem() {
	uint64_t result{ 0 };
	
	std::string numberOne = "654646846453489";
	std::string numberTwo = "546546468415312";
	std::string largeNumber = multipleLargeNumbers(numberOne, numberTwo);

    print << "numberOne = " << numberOne << std::endl;
	print << "numberTwo = " << numberTwo << std::endl;
	print << "largeNumber = " << largeNumber << std::endl;
	
	std::string total = "1";

	for (int i = 0; i < 1000; i++) {
		total = multipleLargeNumbers(total, "2");
	}

	for (char c : total) {
		result = result + atoi(&c);
	}

    print << "The sum is " << result << std::endl;

	return result;
}

static const std::optional<uint64_t> answer{ 1366 };

static const ProblemRegistrar problem_registrar{ Problem{ 16, title, body, problem, answer } };
