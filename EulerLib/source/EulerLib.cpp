#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

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

	for (uint64_t i = num2.size() - 1; i >= 0; i--) {
		auto carry = 0;
		auto base = 0;
		num3 = "";

		for (uint64_t j = num1.size() - 1; j >= 0; j--) {
			auto n1 = num1.at(j);
			auto n2 = num2.at(i);

			auto n3 = (n1 * n2) + carry;

			base = n3 % 10;
			carry = n3 / 10;

			num3 += (base + 48);
		}

		if (carry != 0) {
			num3 += (carry + 48);
		}

		std::reverse(num3.begin(), num3.end());

		for (uint64_t k = num2.size() - 2 - i; k >= 0; k--) {
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
		auto length = str1.size() - str2.size();
		std::string padding(length, '0');
		str2 = padding + str2;
	}
	else {
		auto length = str2.size() - str1.size();
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

std::vector<uint64_t> primeFactors(uint64_t number) {
	auto limit = sqrt(number);
	std::vector<uint64_t> listOfPrimes;

	while (number % 2 == 0) {
		listOfPrimes.push_back(2);
		number /= 2;
	}

	for (int i = 3; i < limit; i += 2) {
		while (number % i == 0) {
			listOfPrimes.push_back(i);
			number /= i;
		}
	}

	return listOfPrimes;
}

bool isPalindrome(int number) {
	std::string forward = std::to_string(number);
	std::string backward = forward;
	std::reverse(backward.begin(), backward.end());

	return (forward == backward);
}

bool isDivisibleByRange(int begin, int end, int number) {
	for (int i = begin; i <= end; i++) {
		if (!(number % i == 0)) {
			return false;
		}
	}

	return true;
}

int sumOfSquares(int number) {
	int result = 0;

	for (int i = 1; i <= number; i++) {
		result += i * i;
	}

	return result;
}

int squareOfSums(int number) {
	int result = 0;

	for (int i = 1; i <= number; i++) {
		result += i;
	}
	result = result * result;

	return result;
}

bool checkPrime(int n) {
	if (n == 2) return true;
	if (n < 2 || n % 2 == 0) return false;

	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}

int getPrimeByIndex(int index) {
	int counter = 0;
	int prime = 0;
	int number = 1;

	bool result = false;

	while (counter < index) {
		result = checkPrime(number);
		if (result == true) {
			prime = number;
			counter++;
		}
		number++;
	}

	return prime;
}

int collatz(int number) {
	int result = 1;
	uint64_t temp = number;

	while (temp != 1) {
		if (temp % 2 == 0) {
			temp = temp / 2;
		}
		else {
			temp = (3 * temp) + 1;
		}
		result++;
	}

	return result;
}

std::vector<bool> setBits(std::string bitString) {
	std::vector<bool> result;

	for (auto b : bitString) {
		if (b == '0') {
			result.push_back(false);
		}
		else if (b == '1') {
			result.push_back(true);
		}
	}

	return result;
}

std::vector<bool> shiftBits(std::vector<bool> bits, int numberOfBits, int amountToShift) {
	std::vector<bool> result = bits;

	auto begin = result.begin();
	auto end = result.end() - 1;
	auto midpoint = result.size() / 2;

	if ((numberOfBits > 0) && (amountToShift > 0)) {
		for (int i = 0; i < numberOfBits; i++) {
			std::iter_swap(begin + midpoint - 1 - i, begin + midpoint - 1 - i + amountToShift);
		}
	}

	return result;
}

SolutionStruct recursiveShifts(SolutionStruct solution) {
	SolutionStruct s;



	return s;
}


template<typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
	for (auto b : v) {
		out << b;
	}
	return out;
}

std::string makeStringFromNumber(int number) {
	std::string result;

	std::string textnum = std::to_string(number);

	for (uint64_t i = 0; i < textnum.length(); i++) {
		if (textnum.at(i) == '1') { result += "one"; }
		if (textnum.at(i) == '2') { result += "two"; }
		if (textnum.at(i) == '3') { result += "three"; }
		if (textnum.at(i) == '4') { result += "four"; }
		if (textnum.at(i) == '5') { result += "five"; }
		if (textnum.at(i) == '6') { result += "six"; }
		if (textnum.at(i) == '7') { result += "seven"; }
		if (textnum.at(i) == '8') { result += "eight"; }
		if (textnum.at(i) == '9') { result += "nine"; }

		if (textnum.length() - i == 4) {
			if (textnum.at(i + 1) == '0' && textnum.at(i + 2) == '0' && textnum.at(i + 3) == '0') {
				result += "thousand";
				return result;
			}
			else { result += "thousand"; }
		}

		else if (textnum.length() - i == 3) {
			if (textnum.at(i + 1) == '0' && textnum.at(i + 2) == '0') { result += "hundred"; return result; }
			if (textnum.at(i) == '0') { result += "and"; }
			else { result += "hundredand"; }
		}

		else if (textnum.length() - i == 2) {
			if (textnum.at(i) == 0 && textnum.at(i + 1) == 0) { return result; }

			if (textnum.at(i) == '0') {
				if (textnum.at(i + 1) == '1') { result += "one"; return result; }
				if (textnum.at(i + 1) == '2') { result += "two"; return result; }
				if (textnum.at(i + 1) == '3') { result += "three"; return result; }
				if (textnum.at(i + 1) == '4') { result += "four"; return result; }
				if (textnum.at(i + 1) == '5') { result += "five"; return result; }
				if (textnum.at(i + 1) == '6') { result += "six"; return result; }
				if (textnum.at(i + 1) == '7') { result += "seven"; return result; }
				if (textnum.at(i + 1) == '8') { result += "eight"; return result; }
				if (textnum.at(i + 1) == '9') { result += "nine"; return result; }
			}
			if (textnum.at(i) == '1') {
				if (textnum.at(i + 1) == '0') { result = result.substr(0, result.length() - 3); result += "ten"; return result; }
				if (textnum.at(i + 1) == '1') { result = result.substr(0, result.length() - 3); result += "eleven"; return result; }
				if (textnum.at(i + 1) == '2') { result = result.substr(0, result.length() - 3); result += "twelve"; return result; }
				if (textnum.at(i + 1) == '3') { result = result.substr(0, result.length() - 3); result += "thirteen"; return result; }
				if (textnum.at(i + 1) == '4') { result = result.substr(0, result.length() - 3); result += "fourteen"; return result; }
				if (textnum.at(i + 1) == '5') { result = result.substr(0, result.length() - 3); result += "fifteen"; return result; }
				if (textnum.at(i + 1) == '6') { result = result.substr(0, result.length() - 3); result += "sixteen"; return result; }
				if (textnum.at(i + 1) == '7') { result = result.substr(0, result.length() - 3); result += "seventeen"; return result; }
				if (textnum.at(i + 1) == '8') { result = result.substr(0, result.length() - 3); result += "eighteen"; return result; }
				if (textnum.at(i + 1) == '9') { result = result.substr(0, result.length() - 3); result += "nineteen"; return result; }
			}
			else if (textnum.at(i) == '2') { result = result.substr(0, result.length() - 3); result += "twen"; }
			else if (textnum.at(i) == '3') { result = result.substr(0, result.length() - 5); result += "thir"; }
			else if (textnum.at(i) == '4') { result = result.substr(0, result.length() - 4); result += "for"; }
			else if (textnum.at(i) == '5') { result = result.substr(0, result.length() - 4); result += "fif"; }
			else if (textnum.at(i) == '8') { result = result.substr(0, result.length() - 1); }

			if (textnum.at(i + 1) == '0') {
				result += "ty";
			}
			else {
				result += "ty";
			}
		}
	}

	return result;
}

std::vector<std::string> loadTriangle(std::string fileName) {
	std::vector<std::string> result;
	std::ifstream triangleFile(fileName);
	std::string line;

	if (triangleFile.is_open()) {
		while (std::getline(triangleFile, line)) {
			if (line.size() > 0) {
				result.push_back(line);
			}
		}
	}
	else {
		std::cout << "Failed to open file." << std::endl;
	}
	triangleFile.close();

	return result;
}

