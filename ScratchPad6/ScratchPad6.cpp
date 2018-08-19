// ScratchPad6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

struct Solution {
	int numberOfBits;
	int amountToShift;
	std::vector<bool> bits;
};

std::vector<bool> setBits(std::string bitString);
Solution calualte(Solution input);

int main()
{
	std::string start = "1111111111111111111100000000000000000000";
	auto bits = setBits(start);
	uint64_t counter = 1;
	
	Solution solution = { 20, 20 };

	std::cout << solution.amountToShift << ", " << solution.numberOfBits << std::endl;
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

Solution calualte(Solution input) {
	Solution result;

	auto numberOfBits = input.numberOfBits;
	auto amountToShift = input.amountToShift;

	int bitLoop = 1;
	int shiftLoop = 1;

	

	return result;
}
