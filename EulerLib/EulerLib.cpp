#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "EulerLib.h"

int fib(int number) {
	if (number == 1) {
		return 1;
	}
	else if (number == 2) {
		return 2;
	}
	else {
		return fib(number - 2) + fib(number - 1);
	}
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

std::vector<uint64_t> getFactors(uint64_t number) { // broken for 4
	std::vector<uint64_t> factors;

	if (number == 0) { factors.push_back(0); return factors; }
	if (number == 1) { factors.push_back(1); return factors; }

	uint64_t lower = number;

	for (uint64_t i = 1; i < lower; i++) {
		if (number % i == 0) {
			factors.push_back(i);
			factors.push_back(number / i);
			lower = number / i - 1;
		}
	}
	
	std::sort(factors.begin(), factors.end());

	return factors;
}

std::vector<uint64_t> getProperDivisors(uint64_t number) {
	std::vector<uint64_t> result;

	result = getFactors(number);

	if (result.size() > 1) {
		result.erase(result.end() - 1);
	}

	return result;
}

uint64_t sumOfVector(std::vector<uint64_t> numbers) {
	uint64_t result = 0;

	for (auto num : numbers) {
		result += num;
	}

	return result;
}
