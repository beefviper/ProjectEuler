// problem0015.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"
#include "print.h"
#include "eulerlib.h"

#include <string>

namespace pe = ProjectEuler;

static const pe::Number number{ 15 };

static const std::string title{ "Lattice paths" };

static const std::string question{ R"(
Starting in the top left corner of a 2x2 grid, and only being able to
move to the right and down, there are exactly 6 routes to the bottom
right corner.

How many such routes are there through a 20x20 grid ?
)" };

static pe::Number solution()
{
	pe::Number result{ 0 };

	std::string start = "1111111111111111111100000000000000000000";
	pe::Number counter = 0;

    pe::print << start << " [" << ++counter << "]" << pe::endl;

	auto bits = pe::setBits(start);
	auto begin = bits.begin();
	auto end = bits.end() - 1;
	auto midpoint = start.length() / 2;

    return result;
}

static const std::string answer{ "The number of lattice paths through a 20x20 grid is: {}" };

[[maybe_unused]] static const pe::Number expected{};

static const pe::ProblemRegistrar problem_registrar{ number, title, question, solution, answer };
