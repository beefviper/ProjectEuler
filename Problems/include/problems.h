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

struct Problem {
	uint64_t number{ 0 };
	std::string title{};
	std::string question{};
	std::function<uint64_t()> solution;
	std::string answer{};
	std::optional<uint64_t> expected{};
	std::optional<uint64_t> result{};

	Problem(uint64_t n,
		std::string t = {},
		std::string q = {},
		std::function<uint64_t()> s = {},
		std::string a = {},
		std::optional<uint64_t> e = {})
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
