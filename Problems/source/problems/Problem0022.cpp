// Problem0022.cpp : This file contains the 'main' function.

/*
Names scores
Problem 22

Using names.txt (right click and 'Save Link/Target As...'), a 46K text file
containing over five-thousand first names, begin by sorting it into
alphabetical order. Then working out the alphabetical value for each name,
multiply this value by its alphabetical position in the list to obtain
a name score.

For example, when the list is sorted into alphabetical order, COLIN,
which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list.
So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?

Answer: 871198282
*/

#include "ProjectEuler.h"

uint64_t problem22()
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

	for (int i = 0; i < max; i++) {
		std::string currName = names.at(i);
		int total = 0;

		for (char c : currName) {
			int temp = (int)c - 64;
			total += temp;
		}

		nameScore[names.at(i)] = (i + 1) * total;
	}

	for (auto it = nameScore.cbegin(); it != nameScore.cend(); ++it) {
		//std::cout << it->first << " = " << it->second << std::endl;
		result += it->second;
	}

	//std::cout << "The sum of all the name scores is " << result << std::endl;

	return result;
}
