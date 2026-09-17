// problem0021.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"
#include "print.h"
#include "eulerlib.h"

#include <map>
#include <string>
#include <vector>

namespace pe = ProjectEuler;

static const pe::value number{ 21 };

static const std::string title{ "Amicable numbers" };

static const std::string question{ R"(
Let d(n) be defined as the sum of proper divisors of n
(numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a != b, then a and b are an amicable
pair and each of a and b are called amicable numbers.

Evaluate the sum of all the amicable numbers under 10000.
)" };

static pe::value solution()
{
	pe::value result{ 0 };
	pe::value number{ 496 };
	pe::value max_num{ 10000 };
	std::vector<pe::value> factors = pe::getFactors(number);
	std::vector<pe::value> properDivisors = pe::getProperDivisors(number);
	pe::value answer = pe::sumOfVector(properDivisors);
	
    pe::print << "The factors of " << number << " are ";
	for (auto f : factors) {
       pe::print << f << ", ";
	}
   pe::print << pe::endl;

    pe::print << "The proper divisors of " << number << " are ";
	for (auto d : properDivisors) {
       pe::print << d << ", ";
	}
   pe::print << pe::endl;

    pe::print << "The sum of the divisors of " << number << " is "
		<< answer << pe::endl;
	
	std::map<pe::value, pe::value> numbers;
	std::vector<pe::value> vecOfNumbers;
	pe::value number_max = 0;

	for (pe::value i = 1; i < max_num; i++) {
		std::vector<pe::value> numberDivisors = pe::getProperDivisors(i);
		pe::value numberDivisorsSum = pe::sumOfVector(numberDivisors);

		numbers[i] = numberDivisorsSum;

		if (numberDivisorsSum > number_max) {
			number_max = numberDivisorsSum;
		}
	}

	for (pe::value i = max_num; i <= number_max; i++) {
		numbers[i] = 1;
	}

	for (pe::value i = 1; i < max_num; i++) {
		pe::value a = numbers.at(i);
		pe::value b = numbers.at(a);

		if ( b == i && b != a ) {
			vecOfNumbers.push_back(i);
		}
	}

	for (auto n : vecOfNumbers) {
        pe::print << n << ", ";
		result += n;
	}
    pe::print << pe::endl;

    pe::print << "Total is " << result << pe::endl;

	return result;
}

static const std::string answer{ "The sum of all the amicable numbers under 10000 is: {}" };

static const pe::value expected{ 31626 };

static const pe::ProblemRegistrar problem_registrar{ number, title, question, solution, answer, expected };
