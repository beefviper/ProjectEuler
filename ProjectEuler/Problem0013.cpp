// Problem0013.cpp : Defines the entry point for the console application.

/*
Problem 13: Large sum

Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

Answer: 5537376230
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

std::string addLargeNumbers(std::string num1, std::string num2);
std::vector<int> createNumber(std::string number);
std::vector<std::string> loadNumbers(std::string fileName);

int problem13()
{
	std::string numbersFileName = "numbers.txt";
	std::vector<std::string> numbers = loadNumbers(numbersFileName);
	std::string total(50, '0');
	
	for (auto number : numbers) {
		std::cout << number << std::endl;
		total = addLargeNumbers(total, number);
	}

	std::cout << "The total is " << total << "." << std::endl;

	system("PAUSE");
    return 0;
}
