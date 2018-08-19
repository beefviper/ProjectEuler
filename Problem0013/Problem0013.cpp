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

int main()
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

std::string addLargeNumbers(std::string numberOne, std::string numberTwo) {
	std::string result;

	std::string str1 = numberOne;
	std::string str2 = numberTwo;

	if (str1.size() > str2.size()) {
		int length = str1.size() - str2.size();
		std::string padding(length, '0');
		str2 = padding + str2;
	}
	else {
		int length = str2.size() - str1.size();
		std::string padding(length, '0');
		str1 = padding + str1;
	}

	auto num1 = createNumber(str1);
	auto num2 = createNumber(str2);

	int temp = 0;
	int carry = 0;
	for (int i = (int)num1.size() - 1; i >= 0; i--) {
		temp = num1.at(i) + num2.at(i) + carry;
		carry = 0;

		if (temp > 9) {
			temp = temp % 10;
			carry = 1;
		}
		result += (temp + 48);
	}

	std::reverse(result.begin(), result.end());

	if (carry == 1) {
		result.insert(0, "1");
	}

	return result;
}

std::vector<int> createNumber(std::string number) {
	std::vector<int> result;

	for (char c : number) {
		result.push_back(atoi(&c));
	}

	return result;
}

std::vector<std::string> loadNumbers(std::string fileName) {
	std::vector<std::string> result;
	std::ifstream numbersFile(fileName);
	std::string number;

	if (numbersFile.is_open()) {
		while (std::getline(numbersFile, number)) {
			if (number.size() > 0) {
				result.push_back(number);
			}
		}
	}
	else {
		std::cout << "Failed to open file." << std::endl;
	}
	numbersFile.close();

	return result;
}
