/* Problem0009.cpp        */
/* author  : beefviper    */
/* version : 0.1          */
/* date    : Jul 01, 2022 */

/*
Problem 9: Special Pythagorean triplet

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2

For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

Answer: 31875000
*/

#include "ProjectEuler.h"

uint64_t problem9()
{
	uint64_t result{ 0 };

	uint64_t resultA = 0;
	uint64_t resultB = 0;
	uint64_t resultC = 0;

	for (int a = 1; a < 1000; a++) {
		for (int b = 1; b < 1000; b++) {
			for (int c = 1; c < 1000; c++) {
				if (a + b + c == 1000) {
					if (a*a + b * b == c * c) {
						resultA = a;
						resultB = b;
						resultC = c;
					}
				}
			}
		}
	}

	int sum = resultA + resultB + resultC;
	result = resultA * resultB * resultC;

	//std::cout << "a = " << resultA << ", b = " << resultB << ", c = " << resultC << std::endl;
	//std::cout << resultA << "^2 * " << resultB << "^2 = " << resultC << "^2" << std::endl;
	//std::cout << resultA << " + " << resultB << " + " << resultC << " = " << sum << std::endl;
	//std::cout << "The product of abc is " << result << "." << std::endl;

    return result;
}
