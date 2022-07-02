/* Problem0006.cpp        */
/* author  : beefviper    */
/* version : 0.1          */
/* date    : Jul 01, 2022 */

/*
Problem 6: Sum square difference

The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 55^2 = 3025

Hence the difference between the sum of the squares of the first ten
natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one
hundred natural numbers and the square of the sum.

Answer: 25164150
*/

#include "ProjectEuler.h"

uint64_t problem6()
{
	uint64_t result{ 0 };
	uint64_t limit{ 100 };

	result = squareOfSums(limit) - sumOfSquares(limit);

	//std::cout << "The difference between the sum of the squares of the"
	//	<< " first one hundred natural numbers and the square of the sum is "
	//	<< result << "." << std::endl;
	
	return result;
}
