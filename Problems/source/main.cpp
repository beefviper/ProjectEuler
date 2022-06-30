// ProjectEuler.cpp : Defines the entry point for the console application.
//

#include "ProjectEuler.h"

int main()
{
	std::vector<Problem> problems;
	createProblems(problems);

	for (auto& problem : problems)
	{
		std::cout << "Problem " << problem.number << " is "
			<< (problem.problem() == problem.answer ? "correct." : "incorrect.")
			<< std::endl;
	}

	return 0;
}
