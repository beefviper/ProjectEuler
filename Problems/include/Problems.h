// problems.h
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

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
#include <utility>
#include <vector>

class ConditionalPrint {
public:
	void setEnabled(bool enabled) {
		enabled_ = enabled;
	}

 template <typename T>
	ConditionalPrint& operator<<(T&& value) {
		if (enabled_) {
			std::cout << std::forward<T>(value);
		}

		return *this;
	}

	ConditionalPrint& operator<<(std::ostream& (*manipulator)(std::ostream&)) {
		if (enabled_) {
			manipulator(std::cout);
		}

		return *this;
	}

private:
	bool enabled_{false};
};

inline ConditionalPrint print;

inline void setPrintEnabled(bool enabled) {
	print.setEnabled(enabled);
}

struct Problem {
	uint64_t number{0};
	std::function<uint64_t()> solution;
	std::optional<uint64_t> answer{};

	Problem(uint64_t n,
			std::function<uint64_t()> s = {},
			std::optional<uint64_t> a = {})
		: number{n}, solution{std::move(s)}, answer{std::move(a)} {}

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
	explicit ProblemRegistrar(Problem problem) {
		problems().emplace_back(std::move(problem));
	}
};
