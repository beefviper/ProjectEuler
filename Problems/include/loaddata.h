// loaddata.h
// Project Euler Problems
// author: beefviper
// date: Sept 17, 2026

#pragma once

#include <optional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace ProjectEuler {

template <typename T>
std::vector<T> loadData(const std::string& source,
	const std::string& startSeq,
	const std::string& endSeq,
	std::optional<size_t> expectedCount = std::nullopt)
{
	// startSeq must be unique in the whole source
	auto start = source.find(startSeq);
	if (start == std::string::npos)
		throw std::runtime_error("loadData: startSeq not found");
	if (source.find(startSeq, start + startSeq.size()) != std::string::npos)
		throw std::runtime_error("loadData: startSeq is not unique");

	// endSeq must be unique, searched only after startSeq
	auto searchFrom = start + startSeq.size();
	auto end = source.find(endSeq, searchFrom);
	if (end == std::string::npos)
		throw std::runtime_error("loadData: endSeq not found after startSeq");
	if (source.find(endSeq, end + endSeq.size()) != std::string::npos)
		throw std::runtime_error("loadData: endSeq is not unique after startSeq");

	end += endSeq.size();

	std::istringstream iss(source.substr(start, end - start));

	std::vector<T> result;
	T value{};
	while (iss >> value)
		result.push_back(value);

	if (iss.fail() && !iss.eof())
		throw std::runtime_error("loadData: failed to parse a value");

	if (expectedCount && result.size() != *expectedCount)
	{
		throw std::runtime_error(
			"loadData: expected " + std::to_string(*expectedCount) +
			" elements, got " + std::to_string(result.size()));
	}

	return result;
}

} // namespace ProjectEuler
