// Problem0004.cpp : Defines the entry point for the console application.

/*
Problem 4: Largest palindrome product

A palindromic number reads the same both ways. The largest palindrome made
from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

Answer: 906609
*/

#include "ProjectEuler.h"

uint64_t problem4()
{
	uint64_t result{ 0 };
	uint64_t num1{ 2203 };
	uint64_t num2{ 906609 };

	//std::cout << num1 << " is " << isPalindrome(num1) << std::endl;
	//std::cout << num2 << " is " << isPalindrome(num2) << std::endl;

	uint64_t largestPalindrome{ 0 };
	
	for (int i = 1; i < 1000; i++) {
		for (int j = 1; j < 1000; j++) {
			int testNumber = i * j;

			if (isPalindrome(testNumber)) {
				if (testNumber > largestPalindrome) {
					largestPalindrome = testNumber;
				}
			}
		}
	}
	
	result = largestPalindrome;
	//std::cout << "The largest palindrome made from the product of two 3-digit"
	//	<< " numbers is " << result << "." << std::endl;

	return result;
}
