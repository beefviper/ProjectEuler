// problem0004.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"
#include "print.h"
#include "eulerlib.h"

#include <string>

namespace pe = ProjectEuler;

static const pe::value number{ 4 };

static const std::string title{ "Largest palindrome product" };

static const std::string question{ R"(
A palindromic number reads the same both ways. The largest palindrome made
from the product of two 2-digit numbers is 9009 = 91 x 99.

Find the largest palindrome made from the product of two 3-digit numbers.
)" };

static pe::value solution()
{
	pe::value result{ 0 };
	pe::value num1{ 2203 };
	pe::value num2{ 906609 };

    pe::print << num1 << " is " << pe::isPalindrome(num1) << pe::endl;
	pe::print << num2 << " is " << pe::isPalindrome(num2) << pe::endl;

	pe::value largestPalindrome{ 0 };
	
	for (pe::value i = 1; i < 1000; i++) {
		for (pe::value j = 1; j < 1000; j++) {
			pe::value testNumber = i * j;

			if (pe::isPalindrome(testNumber)) {
				if (testNumber > largestPalindrome) {
					largestPalindrome = testNumber;
				}
			}
		}
	}
	
	result = largestPalindrome;
    pe::print << "The largest palindrome made from the product of two 3-digit"
		<< " numbers is " << result << "." << pe::endl;

	return result;
}

static const std::string answer{ "The largest palindrome made from the product of two 3-digit numbers is: {}" };

static const pe::value expected{ 906609 };

static const pe::ProblemRegistrar problem_registrar{ number, title, question, solution, answer, expected };
