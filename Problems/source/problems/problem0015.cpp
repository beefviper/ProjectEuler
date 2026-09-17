// problem0015.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"

#include "eulerlib.h"
#include "print.h"

#include <iostream>
#include <optional>
#include <string>
#include <cstdint>

namespace pe = ProjectEuler;

static const uint64_t number{ 15 };

static const std::string title{ "Lattice paths" };

static const std::string body{ R"(
Starting in the top left corner of a 2x2 grid, and only being able to
move to the right and down, there are exactly 6 routes to the bottom
right corner.

How many such routes are there through a 20x20 grid ?
)" };

static uint64_t problem()
{
	uint64_t result{ 0 };

	std::string start = "1111111111111111111100000000000000000000";
	uint64_t counter = 0;

    pe::print << start << " [" << ++counter << "]" << std::endl;

	auto bits = pe::setBits(start);
	auto begin = bits.begin();
	auto end = bits.end() - 1;
	auto midpoint = start.length() / 2;

    return result;
}

static const std::optional<uint64_t> answer{ std::nullopt };

static const pe::ProblemRegistrar problem_registrar{ number, title, body, problem, answer };
