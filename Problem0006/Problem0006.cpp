// Problem0006.cpp : Defines the entry point for the console application.

/*
Problem 6: Sum square difference

The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 55^2 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

Answer: 25164150
*/

#include "stdafx.h"
#include <iostream>

int sumOfSquares(int number);
int squareOfSums(int number);

int main()
{
	int limit = 100;

	int result = squareOfSums(limit) - sumOfSquares(limit);

	std::cout << "The difference between the sum of the squares of the first one hundred natural numbers and the square of the sum is " << result << "." << std::endl;
	
	system("PAUSE");
	return 0;
}

int sumOfSquares(int number) {
	int result = 0;

	for (int i = 1; i <= number; i++) {
		result += i * i;
	}

	return result;
}

int squareOfSums(int number) {
	int result = 0;

	for (int i = 1; i <= number; i++) {
		result += i;
	}
	result = result * result;

	return result;
}