// Problem0015.cpp : Defines the entry point for the console application.

/*
Problem 15: Lattice paths

Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid ?

Answer: 
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

struct SolutionStruct
{
	std::vector<bool> bits;
	int numberOfBits;
	int amountToShift;
};

std::vector<bool> setBits(std::string bitString);
std::vector<bool> shiftBits(std::vector<bool> bits, int numberOfBits, int amountToShift);
SolutionStruct recursiveShifts(SolutionStruct solution);

int main()
{
	std::string start = "1111111111111111111100000000000000000000";
	uint64_t counter = 0;

	std::cout << start << " [" << ++counter << "]" << std::endl;

	auto bits = setBits(start);
	auto begin = bits.begin();
	auto end = bits.end() - 1;
	auto midpoint = start.length() / 2;



	system("PAUSE");
    return 0;
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
