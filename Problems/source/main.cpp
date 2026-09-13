// ProjectEuler.cpp : Defines the entry point for the console application.
//

#include "Problems.h"

int main()
{
	auto allProblems = problems();
	std::sort(allProblems.begin(), allProblems.end(), [](const Problem& left, const Problem& right)
		{
			return left.number < right.number;
		});

	for (auto& problem : allProblems)
	{
		if (!problem.solution)
		{
			std::cout << "Problem " << problem.number << " has no solution function." << std::endl;
			continue;
		}

		const auto result = problem.solution();
		if (problem.answer.has_value())
		{
			std::cout << "Problem " << problem.number << " is "
				<< (problem.answer.value() == result ? "correct." : "incorrect.")
				<< std::endl;
		}
		else
		{
			std::cout << "Problem " << problem.number << " produced " << result << "." << std::endl;
		}
	}

	return 0;
}
