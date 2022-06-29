// ProjectEuler.cpp : Defines the entry point for the console application.
//

#include "ProjectEuler.h"

int main()
{
	std::vector<Problem> problems;
	createProblems(problems);

	for (auto& problem : problems)
	{
		if (problem.fnPtrProblem() == problem.answer)
		{
			std::cout << "Problem " << problem.number << " solution is correct." << std::endl;
		}
		else
		{
			std::cout << "Problem " << problem.number << " solution is incorrect." << std::endl;
		}
	}

	return 0;
}

