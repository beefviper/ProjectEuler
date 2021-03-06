// Problem0007.cpp : Defines the entry point for the console application.

/*
Problem 7: 10001st prime

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

Answer: 104743
*/

#include "stdafx.h"

int problem7()
{
	int index = 10001;

	std::cout << "The " << index << "th prime is " << getPrimeByIndex(index) << "." << std::endl;
	
	system("PAUSE");
	return 0;
}
