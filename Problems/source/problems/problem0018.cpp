// problem0018.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "problems.h"
#include "print.h"
#include "eulerlib.h"

#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>

namespace pe = ProjectEuler;

static const pe::Number number{ 18 };

static const std::string title{ "Maximum path sum I" };

static const std::string question{ R"(
By starting at the top of the triangle below and moving to adjacent
lines on the row below, the maximum total from top to bottom is 23.

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

NOTE: As there are only 16384 routes, it is possible to solve this
problem by trying every route. However, Problem 67, is the same challenge
with a triangle containing one-hundred rows; it cannot be solved by brute
force, and requires a clever method! ;o)
)" };

static pe::Number solution()
{
	pe::Number result{ 0 };

	std::string triangleFileName = "data/large_tri.txt";
	std::vector<std::string> triangleData = pe::loadTriangle(triangleFileName);
	std::vector<std::vector<pe::Number>> triangle;

	for (pe::Number i = 0; i < triangleData.size(); i++) {
		std::stringstream ss(triangleData.at(i));
		std::string s;
		std::vector<pe::Number> v;

		while (std::getline(ss, s, ' ')) {
			v.push_back(atoi(s.c_str()));
		}

		triangle.push_back(v);
	}

   for (auto& v1 : triangle) {
		for (auto v2 : v1) {
           pe::print << v2 << " ";
		}
       pe::print << pe::endl;
	}

	for (pe::Number i = triangle.size() - 2; i >= 0; i--) {
		for (pe::Number j = 0; j < static_cast<pe::Number>(triangle.at(i).size()); j++) {
			pe::Number a = triangle.at(i + 1).at(j);
			pe::Number b = triangle.at(i + 1).at(j + 1);

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
           pe::print << v2 << " ";
		}
       pe::print << pe::endl;
	}

	result = triangle.at(0).at(0);

    pe::print << "result: " << result << pe::endl;
	return result;
}

static const std::string answer{ "The maximum total from top to bottom of the triangle is: {}" };

static const pe::Number expected{ 1074 };

static const pe::ProblemRegistrar problem_registrar{ number, title, question, solution, answer, expected };
