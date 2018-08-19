// ScratchPad5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

template<typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
	for (auto b : v) {
		out << b;
	}
	return out;
}

std::vector<bool> setBits(std::string bitString);

int main()
{
	std::string start = "1111111111111111111100000000000000000000";
	uint64_t counter = 1;

	std::cout << start << " [" << counter << "]" << std::endl;

	auto bits = setBits(start);
	auto begin = bits.begin();
	auto end = bits.end() - 1;
	auto midpoint = start.length() / 2;

	for (int i = 0; i < midpoint; i++) {
		std::iter_swap(begin + midpoint - 1 + i, begin + midpoint + i);
		std::cout << bits;
		counter++;
		std::cout << " [" << counter << "]" << std::endl;
	}

	bits = setBits(start);
	begin = bits.begin();
	end = bits.end() - 1;

	std::iter_swap(begin + midpoint - 1, begin + midpoint);
	std::iter_swap(begin + midpoint - 2, begin + midpoint - 1);
	std::cout << bits << " [" << ++counter << "]" << std::endl;

	for (int i = 0; i < midpoint - 1; i++) {
		std::iter_swap(begin + midpoint + i, begin + midpoint + 1 + i);
		std::cout << bits;
		counter++;
		std::cout << " [" << counter << "]" << std::endl;
	}

	bits = setBits(start);
	begin = bits.begin();
	end = bits.end() - 1;

	std::iter_swap(begin + midpoint - 1, begin + midpoint + 1);
	std::iter_swap(begin + midpoint - 2, begin + midpoint);
	std::cout << bits << " [" << ++counter << "]" << std::endl;

	for (int i = 0; i < midpoint - 2; i++) {
		std::iter_swap(begin + midpoint + i + 1, begin + midpoint + 2 + i);
		std::cout << bits;
		counter++;
		std::cout << " [" << counter << "]" << std::endl;
	}



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
