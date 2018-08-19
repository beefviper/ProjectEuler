// Problem0010.cpp : Defines the entry point for the console application.

/*
Problem 10: Summation of primes

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

Answer: 
*/

#include "stdafx.h"
#include <iostream>

bool checkPrime(int n);

int main()
{
	int limit = 2000000;
	uint64_t total = 0;

	for (int i = 0; i < limit; i++) {
		if (checkPrime(i) == true) {
			total += i;
		}
	}

	std::cout << "The sum of all the primes below " << limit << " is " << total << "." << std::endl;

	system("PAUSE");
    return 0;
}

bool checkPrime(int n) {
	if (n == 2) return true;
	if (n < 2 || n % 2 == 0) return false;

	for (int i = 3; i*i <= n; i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}
