// problem0016.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"
#include "print.h"
#include "eulerlib.h"

#include <cstdlib>
#include <string>

namespace pe = ProjectEuler;

static const pe::value number{ 16 };

static const std::string title{ "Power digit sum" };

static const std::string question{ R"(
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
)" };

static pe::value solution() {
	pe::value result{ 0 };
	
	std::string numberOne = "654646846453489";
	std::string numberTwo = "546546468415312";
	std::string largeNumber = pe::multipleLargeNumbers(numberOne, numberTwo);

    pe::print << "numberOne = " << numberOne << pe::endl;
	pe::print << "numberTwo = " << numberTwo << pe::endl;
	pe::print << "largeNumber = " << largeNumber << pe::endl;
	
	std::string total = "1";

	for (int i = 0; i < 1000; i++) {
		total = pe::multipleLargeNumbers(total, "2");
	}

	for (char c : total) {
		result = result + atoi(&c);
	}

    pe::print << "The sum is " << result << pe::endl;

	return result;
}

static const std::string answer{ "The sum of the digits of the number 2^1000 is: {}" };

static const pe::value expected{ 1366 };

static const pe::ProblemRegistrar problem_registrar{ number, title, question, solution, answer, expected };
