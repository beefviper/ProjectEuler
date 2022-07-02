/* Problem0020.cpp        */
/* author  : beefviper    */
/* version : 0.1          */
/* date    : Jul 01, 2022 */

/*
Problem 20: Factorial digit sum

n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is
3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!

Answer: 648
*/

#include "ProjectEuler.h"

uint64_t problem20()
{
	uint64_t result{ 0 };
	uint64_t number{ 100 };
	std::string answer = "1";

	for (int i = 1; i <= number; i++) {
		answer = multipleLargeNumbers(answer, std::to_string(i));
	}

	//std::cout << "The factorial of " << number << " is "
	//	<< answer << std::endl;

	for (char c : answer) {
		result += atoi(&c);
	}

	//std::cout << "The sum of all the digits is " << result << std::endl;

	return result;
}
