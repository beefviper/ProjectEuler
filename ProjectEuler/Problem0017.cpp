// Problem0017.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
Problem 17: Number letter counts

If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

Answer: 21124
*/

#include "stdafx.h"

int problem17()
{
	int number = 1000;
	int total = 0;

	//std::string words = makeStringFromNumber(9999);

	for (int i = 1; i <= number; i++) {
		std::string words = makeStringFromNumber(i);
		std::cout << words << std::endl;
		total += words.length();
	}

	std::cout << "The total is " << total << "." << std::endl;

	system("PAUSE");
	return 0;
}
