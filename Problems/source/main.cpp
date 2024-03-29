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
			<< (problem.answer == problem.solution() ? "correct." : "incorrect.")
			<< std::endl;
	}

	return 0;
}
