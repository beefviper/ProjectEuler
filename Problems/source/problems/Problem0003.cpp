// Problem0003.cpp : Defines the entry point for the console application.

/*
Problem 3: Largest prime factor

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

Answer: 6857
*/

#include "Problems.h"

uint64_t problem3()
{
	uint64_t result{ 0 };
	uint64_t numberToFactor{ 600851475143 };
	std::vector<uint64_t> factors = primeFactors(numberToFactor);

	//std::cout << "The prime factors of " << numberToFactor << " is ";
	for (uint64_t factor : factors) {
		//std::cout << factor << ", ";
	}
	//std::cout << std::endl;

	if (!factors.empty()) {
		result = factors.back();
		//std::cout << "The largest prime factor of " << numberToFactor << " is "
		//	<< result << std::endl;
	}
	else {
		//std::cout << "There are no prime factors." << std::endl;
	}

    return result;
}

static const ProblemRegistrar problem3_registrar{ Problem{ 3, problem3, 6857 } };
