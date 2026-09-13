// Problem0015.cpp : Defines the entry point for the console application.

/*
Problem 15: Lattice paths

Starting in the top left corner of a 2Ã—2 grid, and only being able to
move to the right and down, there are exactly 6 routes to the bottom
right corner.

How many such routes are there through a 20Ã—20 grid ?

Answer: 
*/

#include "Problems.h"

uint64_t problem15()
{
	uint64_t result{ 0 };

	std::string start = "1111111111111111111100000000000000000000";
	uint64_t counter = 0;

	//std::cout << start << " [" << ++counter << "]" << std::endl;

	auto bits = setBits(start);
	auto begin = bits.begin();
	auto end = bits.end() - 1;
	auto midpoint = start.length() / 2;

    return result;
}

static const ProblemRegistrar problem15_registrar{ Problem{ 15, problem15 } };
