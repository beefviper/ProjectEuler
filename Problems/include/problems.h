// problems.h
// Project Euler Problems
// author: beefviper
// date: Sept 17, 2026

#pragma once

#include <concepts>
#include <cstdint>
#include <functional>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace ProjectEuler {

using value = uint64_t;

struct Problem {
	value number{ 0 };
	std::string title{};
	std::string question{};
	std::function<value()> solution;
	std::string answer{};
	std::optional<value> expected{};
	std::optional<value> result{};

	Problem(value n,
		std::string t = {},
		std::string q = {},
		std::function<value()> s = {},
		std::string a = {},
		std::optional<value> e = {})
		: number{ n }, title{ std::move(t) }, question{ std::move(q) },
		solution{ std::move(s) }, answer{ std::move(a) }, expected{ std::move(e) } {}
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

} // namespace ProjectEuler
