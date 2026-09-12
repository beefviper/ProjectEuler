#pragma once

#include "EulerLib.h"

#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

struct Problem
{
	uint64_t number{ 0 };
	uint64_t(*solution)() { nullptr };
	std::optional<uint64_t> answer{};
};

inline std::vector<Problem>& problems()
{
	static std::vector<Problem> allProblems;
	return allProblems;
}

struct ProblemRegistrar
{
	ProblemRegistrar(uint64_t number, uint64_t(*solution)(), std::optional<uint64_t> answer = std::nullopt)
	{
		problems().emplace_back(Problem{ number, solution, answer });
	}
};
