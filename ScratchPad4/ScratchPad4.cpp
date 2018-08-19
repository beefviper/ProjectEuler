// ScratchPad4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

int main()
{
	std::vector<bool> moves = { 1, 1, 1, 0, 0, 0 };
	int length = moves.size();
	int midpoint = length / 2;
	uint64_t max = 1099510579200;
	uint64_t min = 1048575;

	for (auto c : moves) {
		std::cout << c << ", ";
	}
	std::cout << std::endl;

	auto begin = moves.begin();
	auto end = moves.end() - 1;
	std::iter_swap(begin, end);

	for (auto c : moves) {
		std::cout << c << ", ";
	}
	std::cout << std::endl;

	std::bitset<40> bitsMax(max);
	std::bitset<40> bitsMin(min);

	std::cout << bitsMax << std::endl;
	std::cout << bitsMin << std::endl;

	uint64_t counter = 0;

	for (uint64_t i = max; i >= min; i--) {
		std::bitset<40> temp(i);
		if (temp.count() == 20) {
			counter++;
		}

	}

	std::cout << "There are " << counter << " routes through a 20×20 grid." << std::endl;

	system("PAUSE");
	return 0;
}
