// menu.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "menu.h"

#include <algorithm>
#include <iostream>

namespace ProjectEuler {

Menu::Menu(uint64_t problemNumber, PrintMode printMode)
    : problemNumber_{problemNumber}, printMode_{printMode} {
    auto& allProblems = problems();
    std::sort(allProblems.begin(), allProblems.end(), [](const Problem& left, const Problem& right)
        {
            return left.number < right.number;
        });
}

int Menu::run() const {
    setPrintEnabled(hasFlag(printMode_, PrintMode::solution));

    const auto& allProblems = problems();

    if (problemNumber_ == 0)
    {
        for (const auto& problem : allProblems)
        {
            runProblem(problem);
        }

        return 0;
    }

    const auto it = std::find_if(allProblems.begin(), allProblems.end(), [this](const Problem& problem)
        {
            return problem.number == problemNumber_;
        });

    if (it == allProblems.end())
    {
        std::cout << "Problem " << problemNumber_ << " was not found." << std::endl;
        return 1;
    }

    runProblem(*it);
    return 0;
}

void Menu::runProblem(const Problem& problem) const {
    if (!problem.solution)
    {
        std::cout << "Problem " << problem.number << " has no solution function." << std::endl;
        return;
    }

    if (hasFlag(printMode_, PrintMode::question))
    {
        std::cout << "Problem " << problem.number << ": " << problem.title << std::endl;
        std::cout << problem.body << std::endl;
    }

    if (!hasFlag(printMode_, PrintMode::verify) && !hasFlag(printMode_, PrintMode::solution))
    {
        return;
    }

    const auto result = problem.solution();

    if (hasFlag(printMode_, PrintMode::verify))
    {
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
}

} // namespace ProjectEuler
