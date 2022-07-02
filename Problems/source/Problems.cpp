/* Problems.cpp           */
/* author  : beefviper    */
/* version : 0.1          */
/* date    : Jul 01, 2022 */

#include "ProjectEuler.h"

void createProblems(std::vector<Problem>& problems)
{
	problems.emplace_back(Problem{ 1, problem1, 233168 });
	problems.emplace_back(Problem{ 2, problem2, 4613732 });
	problems.emplace_back(Problem{ 3, problem3, 6857 });
	problems.emplace_back(Problem{ 4, problem4, 906609 });
	problems.emplace_back(Problem{ 5, problem5, 232792560 });
	problems.emplace_back(Problem{ 6, problem6, 25164150 });
	problems.emplace_back(Problem{ 7, problem7, 104743 });
	problems.emplace_back(Problem{ 8, problem8, 23514624000 });
	problems.emplace_back(Problem{ 9, problem9, 31875000 });
	//problems.emplace_back(Problem{ problem10, ?? });
	problems.emplace_back(Problem{ 11, problem11, 70600674 });
	problems.emplace_back(Problem{ 12, problem12, 76576500 });
	//problems.emplace_back(Problem{ 13, problem13, 5537376230 });
	problems.emplace_back(Problem{ 14, problem14, 837799 });
	//problems.emplace_back(Problem{ 15, problem15, ?? });
	problems.emplace_back(Problem{ 16, problem16, 1366 });
	problems.emplace_back(Problem{ 17, problem17, 21124 });
	problems.emplace_back(Problem{ 18, problem18, 1074 });
	problems.emplace_back(Problem{ 20, problem20, 648 });
	problems.emplace_back(Problem{ 21, problem21, 31626 });
	problems.emplace_back(Problem{ 22, problem22, 871198282 });
	//problems.emplace_back(Problem{ 23, problem23, ?? });
	//problems.emplace_back(Problem{ 25, problem25, ?? });
}
