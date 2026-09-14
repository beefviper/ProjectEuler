// problem0018.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "Problems.h"

// Problem0018.cpp : This file contains the 'main' function.

/*
Problem 18: Maximum path sum I

By starting at the top of the triangle below and moving to adjacent
lines on the row below, the maximum total from top to bottom is 23.

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

NOTE: As there are only 16384 routes, it is possible to solve this
problem by trying every route. However, Problem 67, is the same challenge
with a triangle containing one-hundred rows; it cannot be solved by brute
force, and requires a clever method! ;o)

Answer: 1074
*/


uint64_t problem18()
{
	uint64_t result{ 0 };

	std::string triangleFileName = "data/large_tri.txt";
	std::vector<std::string> triangleData = loadTriangle(triangleFileName);
	std::vector<std::vector<int64_t>> triangle;

	for (uint64_t i = 0; i < triangleData.size(); i++) {
		std::stringstream ss(triangleData.at(i));
		std::string s;
		std::vector<int64_t> v;

		while (std::getline(ss, s, ' ')) {
			v.push_back(atoi(s.c_str()));
		}

		triangle.push_back(v);
	}

   for (auto& v1 : triangle) {
		for (auto v2 : v1) {
           print << v2 << " ";
		}
       print << std::endl;
	}

	for (int64_t i = triangle.size() - 2; i >= 0; i--) {
		for (int64_t j = 0; j < static_cast<int64_t>(triangle.at(i).size()); j++) {
			int64_t a = triangle.at(i + 1).at(j);
			int64_t b = triangle.at(i + 1).at(j + 1);

			if (a > b) {
				triangle.at(i).at(j) += a;
			}
			else {
				triangle.at(i).at(j) += b;
			}
		}
	}

   for (auto& v1 : triangle) {
		for (auto v2 : v1) {
           print << v2 << " ";
		}
       print << std::endl;
	}

	result = triangle.at(0).at(0);

    print << "result: " << result << std::endl;
	return result;
}

static const ProblemRegistrar problem18_registrar{ Problem{ 18, problem18, 1074 } };
