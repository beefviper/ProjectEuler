// ScratchPad.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string addLargeNumbers(std::string num1, std::string num2);
std::vector<int> createNumber(std::string number);

int main()
{
	std::string numberOneString = "6438";
	std::string numberTwoString = "5125";

	auto resultString = addLargeNumbers(numberOneString, numberTwoString);

	std::cout << numberOneString << std::endl;
	std::cout << numberTwoString << std::endl;
	std::cout << resultString << std::endl;

	system("PAUSE");
	return 0;
}

std::string addLargeNumbers(std::string numberOne, std::string numberTwo) {
	std::string result;

	auto num1 = createNumber(numberOne);
	auto num2 = createNumber(numberTwo);

	int temp = 0;
	int carry = 0;
	for (int i = (int)num1.size() - 1; i >= 0 ; i--) {
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
