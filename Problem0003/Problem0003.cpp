// Problem0003.cpp : Defines the entry point for the console application.

/*
Problem 3: Largest prime factor

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

Answer: 6857
*/

#include "stdafx.h"
#include <cstdint>
#include <iostream>
#include <vector>

std::vector<uint64_t> primeFactors(uint64_t number);

int main()
{
	auto numberToFactor = 1;
	std::vector<uint64_t> factors = primeFactors(numberToFactor);

	std::cout << "The prime factors of " << numberToFactor << " is ";
	for (uint64_t factor : factors) {
		std::cout << factor << ", ";
	}
	std::cout << std::endl;

	if (!factors.empty()) {
		std::cout << "The largest prime factor of " << numberToFactor << " is " << factors.back() << std::endl;
	}
	else {
		std::cout << "There are no prime factors." << std::endl;
	}

	system("PAUSE");
    return 0;
}

std::vector<uint64_t> primeFactors(uint64_t number) {
	auto limit = sqrt(number);
	std::vector<uint64_t> listOfPrimes;

	while (number % 2 == 0) {
		listOfPrimes.push_back(2);
		number /= 2;
	}

	for (int i = 3; i < limit; i += 2){
		while (number % i == 0) {
			listOfPrimes.push_back(i);
			number /= i;
		}
	}

	return listOfPrimes;
}
