// menu.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "menu.h"

Menu::Menu(uint64_t problemNumber, PrintMode printMode)
    : problemNumber_{problemNumber}, printMode_{printMode} {
}

int Menu::run() const {
    setPrintEnabled(problemNumber_ != 0 &&
        (printMode_ == PrintMode::statements || printMode_ == PrintMode::both));

    auto& allProblems = problems();
    std::sort(allProblems.begin(), allProblems.end(), [](const Problem& left, const Problem& right)
        {
            return left.number < right.number;
        });

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

    if (printMode_ == PrintMode::question || printMode_ == PrintMode::both)
    {
        std::cout << "Problem " << problem.number << ": " << problem.title << std::endl;
        std::cout << problem.body << std::endl;
    }

    const auto result = problem.solution();
    if (problem.answer.has_value())
    {
        std::cout << "Problem " << problem.number << " is "
            << (problem.answer.value() == result ? "correct." : "incorrect.")
            << std::endl << std::endl;
    }
    else
    {
        std::cout << "Problem " << problem.number << " produced " << result << "." << std::endl << std::endl;
    }
}
