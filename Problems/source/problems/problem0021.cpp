// problem0021.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"

#include "eulerlib.h"
#include "print.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstdint>

namespace pe = ProjectEuler;

static const uint64_t number{ 21 };

static const std::string title{ "Amicable numbers" };

static const std::string question{ R"(
Let d(n) be defined as the sum of proper divisors of n
(numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a != b, then a and b are an amicable
pair and each of a and b are called amicable numbers.

Evaluate the sum of all the amicable numbers under 10000.
)" };

static uint64_t solution()
{
	uint64_t result{ 0 };
	uint64_t number{ 496 };
	uint64_t max_num{ 10000 };
	std::vector<uint64_t> factors = pe::getFactors(number);
	std::vector<uint64_t> properDivisors = pe::getProperDivisors(number);
	uint64_t answer = pe::sumOfVector(properDivisors);
	
    pe::print << "The factors of " << number << " are ";
	for (auto f : factors) {
       pe::print << f << ", ";
	}
   pe::print << std::endl;

    pe::print << "The proper divisors of " << number << " are ";
	for (auto d : properDivisors) {
       pe::print << d << ", ";
	}
   pe::print << std::endl;

    pe::print << "The sum of the divisors of " << number << " is "
		<< answer << std::endl;
	
	std::map<uint64_t, uint64_t> numbers;
	std::vector<uint64_t> vecOfNumbers;
	uint64_t number_max = 0;

	for (uint64_t i = 1; i < max_num; i++) {
		std::vector<uint64_t> numberDivisors = pe::getProperDivisors(i);
		uint64_t numberDivisorsSum = pe::sumOfVector(numberDivisors);

		numbers[i] = numberDivisorsSum;

		if (numberDivisorsSum > number_max) {
			number_max = numberDivisorsSum;
		}
	}

	for (uint64_t i = max_num; i <= number_max; i++) {
		numbers[i] = 1;
	}

	for (uint64_t i = 1; i < max_num; i++) {
		uint64_t a = numbers.at(i);
		uint64_t b = numbers.at(a);

		if ( b == i && b != a ) {
			vecOfNumbers.push_back(i);
		}
	}

	for (auto n : vecOfNumbers) {
        pe::print << n << ", ";
		result += n;
	}
    pe::print << std::endl;

    pe::print << "Total is " << result << std::endl;

	return result;
}

static const std::string answer{ "The sum of all the amicable numbers under 10000 is: {}" };

static const pe::ProblemRegistrar problem_registrar{ number, title, question, solution, answer };
