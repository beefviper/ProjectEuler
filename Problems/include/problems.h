// problems.h
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#pragma once

#include "eulerlib.h"
#include "print.h"

#include <algorithm>
#include <concepts>
#include <cstdint>
#include <fstream>
#include <functional>
#include <iomanip>
#include <map>
#include <optional>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

struct Problem {
	uint64_t number{0};
	std::string title{};
	std::string body{};
	std::function<uint64_t()> solution;
	std::optional<uint64_t> answer{};

	Problem(uint64_t n,
			std::string t = {},
			std::string b = {},
			std::function<uint64_t()> s = {},
			std::optional<uint64_t> a = {})
		: number{n}, title{std::move(t)}, body{std::move(b)},
		  solution{std::move(s)}, answer{std::move(a)} {}

	std::optional<uint64_t> try_solve() const {
		return solution ? std::make_optional(solution()) : std::nullopt;
	}
};

inline std::vector<Problem>& problems() {
	static std::vector<Problem> registry;
	return registry;
}

class ProblemRegistrar {
public:
	template<typename... Args>
		requires std::constructible_from<Problem, Args...>
	explicit ProblemRegistrar(Args&&... args) {
		problems().emplace_back(std::forward<Args>(args)...);
	}
};
