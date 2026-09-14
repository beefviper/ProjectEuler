// problem0025.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"

static const std::string title{ "1000-digit Fibonacci number" };

static const std::string body{ R"(
The Fibonacci sequence is defined by the recurrence relation:

	Fn = Fn-1 + Fn-2, where F1 = 1 and F2 = 1.

Hence the first 12 terms will be:

	F1 = 1
	F2 = 1
	F3 = 2
	F4 = 3
	F5 = 5
	F6 = 8
	F7 = 13
	F8 = 21
	F9 = 34
	F10 = 55
	F11 = 89
	F12 = 144

The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to
contain 1000 digits?
)" };


uint64_t problem25()
{
	uint64_t result{ 0 };
	std::string index = "999";
	std::string answer = "0";

    print << "index: " << atoi(index.c_str()) + 1
		<< ", answer: " << answer << std::endl;

	return result;
}

static const std::optional<uint64_t> answer{ std::nullopt };

static const ProblemRegistrar problem25_registrar{ Problem{ 25, title, body, problem25, answer } };
