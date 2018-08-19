// Problem0007.cpp : Defines the entry point for the console application.

/*
Problem 7: 10001st prime

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

Answer: 104743
*/

#include "stdafx.h"
#include <iostream>

int getPrimeByIndex(int index);
bool checkPrime(int n);

int main()
{
	int index = 10001;

	std::cout << "The " << index << "th prime is " << getPrimeByIndex(index) << "." << std::endl;
	
	system("PAUSE");
	return 0;
}

int getPrimeByIndex(int index) {
	int counter = 0;
	int prime = 0;
	int number = 1;

	bool result = false;

	while (counter < index) {
		result = checkPrime(number);
		if (result == true) {
			prime = number;
			counter++;
		}
		number++;
	}

	return prime;
}

bool checkPrime(int n) {
	if (n == 2) return true;
	if (n < 2 || n % 2 == 0) return false;

	for (int i = 3; i*i <= n; i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}
