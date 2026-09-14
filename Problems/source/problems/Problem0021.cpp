// problem0021.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"

static const std::string title{ "Amicable numbers" };

static const std::string body{ R"(
Let d(n) be defined as the sum of proper divisors of n
(numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable
pair and each of a and b are called amicable numbers.

Evaluate the sum of all the amicable numbers under 10000.
)" };

uint64_t problem21()
{
	uint64_t result{ 0 };
	uint64_t number{ 496 };
	uint64_t max_num{ 10000 };
	std::vector<uint64_t> factors = getFactors(number);
	std::vector<uint64_t> properDivisors = getProperDivisors(number);
	uint64_t answer = sumOfVector(properDivisors);
	
    print << "The factors of " << number << " are ";
	for (auto f : factors) {
       print << f << ", ";
	}
   print << std::endl;

    print << "The proper divisors of " << number << " are ";
	for (auto d : properDivisors) {
       print << d << ", ";
	}
   print << std::endl;

    print << "The sum of the divisors of " << number << " is "
		<< answer << std::endl;
	
	std::map<uint64_t, uint64_t> numbers;
	std::vector<uint64_t> vecOfNumbers;
	uint64_t number_max = 0;

	for (uint64_t i = 1; i < max_num; i++) {
		std::vector<uint64_t> numberDivisors = getProperDivisors(i);
		uint64_t numberDivisorsSum = sumOfVector(numberDivisors);

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
        print << n << ", ";
		result += n;
	}
    print << std::endl;

    print << "Total is " << result << std::endl;

	return result;
}

static const std::optional<uint64_t> answer{ 31626 };

static const ProblemRegistrar problem21_registrar{ Problem{ 21, title, body, problem21, answer } };
