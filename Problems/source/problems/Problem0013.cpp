/* Problem0013.cpp        */
/* author  : beefviper    */
/* version : 0.1          */
/* date    : Jul 01, 2022 */

/*
Problem 13: Large sum

Work out the first ten digits of the sum of the following
one-hundred 50-digit numbers.

Answer: 5537376230
*/

#include "ProjectEuler.h"

uint64_t problem13()
{
	uint64_t result{ 0 };
	std::string numbersFileName = "data/numbers.txt";
	std::vector<std::string> numbers = loadNumbers(numbersFileName);
	std::string total(50, '0');
	
	for (auto& number : numbers) {
		//std::cout << number << std::endl;
		total = addLargeNumbers(total, number);
	}

	//std::cout << "The total is " << total << "." << std::endl;

	//result = std::stol(total);

	return result;
}
