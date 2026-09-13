#pragma once
#pragma once

#include "EulerLib.h"

#include <algorithm>
#include <cstdint>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <optional>
#include <sstream>
#include <string>
#include <utility>  // for std::move
#include <vector>

struct Problem {
	uint64_t number{0};
	std::function<uint64_t()> solution;
	std::optional<uint64_t> answer{};

	// REMOVED constexpr — no benefit, and technically false
	Problem(uint64_t n,
			std::function<uint64_t()> s = {},
			std::optional<uint64_t> a = {})
		: number{n}, solution{std::move(s)}, answer{std::move(a)} {}

	// Safe wrapper (no constexpr needed — runtime only)
	std::optional<uint64_t> try_solve() const {
		return solution ? std::make_optional(solution()) : std::nullopt;
	}
};

// Public instance function (renamed to avoid ambiguity)
inline std::vector<Problem>& problems() {
	static std::vector<Problem> registry; // construct-on-first-use: safe & simple
	return registry;
}

class ProblemRegistrar {
public:
	explicit ProblemRegistrar(Problem problem) {
		problems().emplace_back(std::move(problem));
	}
};
