// problem0022.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"

#include "print.h"

#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace pe = ProjectEuler;

static const uint64_t number{ 22 };

static const std::string title{ "Names scores" };

static const std::string question{ R"(
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file
containing over five-thousand first names, begin by sorting it into
alphabetical order. Then working out the alphabetical value for each name,
multiply this value by its alphabetical position in the list to obtain
a name score.

For example, when the list is sorted into alphabetical order, COLIN,
which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list.
So, COLIN would obtain a score of 938 x 53 = 49714.

What is the total of all the name scores in the file?
)" };

static uint64_t solution()
{
	uint64_t result{ 0 };
	std::string namesFilename = "data/names.txt";
	std::ifstream namesFile(namesFilename);

	std::vector<std::string> names;
	std::string name;

	if (namesFile.is_open()) {
		while (std::getline(namesFile, name, ',')) {
			name.erase(std::find(name.begin(), name.end(), '\"'));
			name.erase(std::find(name.begin(), name.end(), '\"'));
			names.push_back(name);
		}
	}

	namesFile.close();

	std::sort(names.begin(), names.end());

	std::map<std::string, uint64_t> nameScore;
	auto max = names.size();

	for (size_t i = 0; i < max; i++) {
		std::string currName = names.at(i);
		int total = 0;

		for (char c : currName) {
			int temp = (int)c - 64;
			total += temp;
		}

		nameScore[names.at(i)] = static_cast<uint64_t>(i + 1) * static_cast<uint64_t>(total);
	}

	for (auto it = nameScore.cbegin(); it != nameScore.cend(); ++it) {
		pe::print << it->first << " = " << it->second << std::endl;
		result += it->second;
	}

	return result;
}

static const std::string answer{ "The sum of all the name scores is {}." };

static const pe::ProblemRegistrar problem_registrar{ number, title, question, solution, answer };