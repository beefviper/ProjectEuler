/* Problem0018.cpp        */
/* author  : beefviper    */
/* version : 0.1          */
/* date    : Jul 01, 2022 */

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

#include "ProjectEuler.h"

uint64_t problem18()
{
	uint64_t result{ 0 };

	std::string triangleFileName = "data/large_tri.txt";
	std::vector<std::string> triangleData = loadTriangle(triangleFileName);
	std::vector<std::vector<int>> triangle;

	for (unsigned int i = 0; i < triangleData.size(); i++) {
		std::stringstream ss(triangleData.at(i));
		std::string s;
		std::vector<int> v;

		while (std::getline(ss, s, ' ')) {
			v.push_back(atoi(s.c_str()));
		}

		triangle.push_back(v);
	}

	//for (auto& v1 : triangle) {
	//	for (auto v2 : v1) {
	//		std::cout << v2 << " ";
	//	}
	//	std::cout << std::endl;
	//}

	for (int i = triangle.size() - 2; i >= 0; i--) {
		for (int j = 0; j < triangle.at(i).size(); j++) {
			int a = triangle.at(i + 1).at(j);
			int b = triangle.at(i + 1).at(j + 1);

			if (a > b) {
				triangle.at(i).at(j) += a;
			}
			else {
				triangle.at(i).at(j) += b;
			}
		}
	}

	//for (auto& v1 : triangle) {
	//	for (auto v2 : v1) {
	//		std::cout << v2 << " ";
	//	}
	//	std::cout << std::endl;
	//}

	return result;
}
