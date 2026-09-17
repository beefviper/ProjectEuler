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

static const pe::Number number{ 21 };

static const std::string title{ "Amicable numbers" };

static const std::string question{ R"(
Let d(n) be defined as the sum of proper divisors of n
(numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a != b, then a and b are an amicable
pair and each of a and b are called amicable numbers.

Evaluate the sum of all the amicable numbers under 10000.
)" };

static pe::Number solution()
{
	pe::Number result{ 0 };
	pe::Number number{ 496 };
	pe::Number max_num{ 10000 };
	std::vector<pe::Number> factors = pe::getFactors(number);
	std::vector<pe::Number> properDivisors = pe::getProperDivisors(number);
	pe::Number answer = pe::sumOfVector(properDivisors);
	
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
	
	std::map<pe::Number, pe::Number> numbers;
	std::vector<pe::Number> vecOfNumbers;
	pe::Number number_max = 0;

	for (pe::Number i = 1; i < max_num; i++) {
		std::vector<pe::Number> numberDivisors = pe::getProperDivisors(i);
		pe::Number numberDivisorsSum = pe::sumOfVector(numberDivisors);

		numbers[i] = numberDivisorsSum;

		if (numberDivisorsSum > number_max) {
			number_max = numberDivisorsSum;
		}
	}

	for (pe::Number i = max_num; i <= number_max; i++) {
		numbers[i] = 1;
	}

	for (pe::Number i = 1; i < max_num; i++) {
		pe::Number a = numbers.at(i);
		pe::Number b = numbers.at(a);

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

static const pe::Number expected{ 31626 };

static const pe::ProblemRegistrar problem_registrar{ number, title, question, solution, answer, expected };
