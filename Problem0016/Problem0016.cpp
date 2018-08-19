// Problem0016.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
Problem 16: Power digit sum

2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?

Answer: 1366
*/

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string multipleLargeNumbers(std::string numOne, std::string numTwo);
std::string addLargeNumbers(std::string numberOne, std::string numberTwo);
std::vector<int> createNumber(std::string number);

int main() {
	/*
	std::string numberOne = "654646846453489";
	std::string numberTwo = "546546468415312";
	std::string largeNumber = multipleLargeNumbers(numberOne, numberTwo);

	std::cout << "numberOne = " << numberOne << std::endl;
	std::cout << "numberTwo = " << numberTwo << std::endl;
	std::cout << "largeNumber = " << largeNumber << std::endl;
	*/

	std::string total = "1";

	for (int i = 0; i < 1000; i++) {
		total = multipleLargeNumbers(total, "2");
	}

	int answer = 0;
	for (char c : total) {
		answer = answer + atoi(&c);
	}

	std::cout << "The sum is " << answer << std::endl;

	system("PAUSE");
	return 0;
}

std::string multipleLargeNumbers(std::string numOne, std::string numTwo) {
	std::string result;
	std::vector<int> num1 = createNumber(numOne);
	std::vector<int> num2 = createNumber(numTwo);
	std::string num3;
	std::vector<std::string> resultVector;

	for (int i = num2.size() - 1; i >= 0; i--) {
		int carry = 0;
		int base = 0;
		num3 = "";

		for (int j = num1.size() - 1; j >= 0; j--) {
			int n1 = num1.at(j);
			int n2 = num2.at(i);

			int n3 = (n1 * n2) + carry;

			base = n3 % 10;
			carry = n3 / 10;

			num3 += (base + 48);
		}
		
		if (carry != 0) {
			num3 += (carry + 48);
		}

		std::reverse(num3.begin(), num3.end());

		for (int k = num2.size() - 2 - i; k >= 0; k--) {
			num3 = num3 + "0";
		}

		std::cout << num3 << std::endl;
		resultVector.push_back(num3);
	}

	std::string total;

	for (std::string v : resultVector) {
		total = addLargeNumbers(total, v);
	}

	result = total;

	return result;
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
