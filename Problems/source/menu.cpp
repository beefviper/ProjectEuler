// menu.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 17, 2026

#include "menu.h"

#include "flags.h"
#include "print.h"
#include "problems.h"

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <iostream>
#include <string>

namespace ProjectEuler {

Menu::Menu() {
    auto& allProblems = problems();
    std::sort(allProblems.begin(), allProblems.end(), [](const Problem& left, const Problem& right)
        {
            return left.number < right.number;
        });
}

int Menu::run() const {
    while (true)
    {
        std::cout << "\nEnter a problem number (0 = verify all, q = quit): ";

        std::string line;
        if (!std::getline(std::cin, line))
        {
            break;
        }

        // trim leading/trailing whitespace
        const auto first = line.find_first_not_of(" \t\r\n");
        if (first == std::string::npos)
        {
            continue; // blank line, reprompt
        }
        const auto last = line.find_last_not_of(" \t\r\n");
        line = line.substr(first, last - first + 1);

        if (line == "q" || line == "Q")
        {
            break;
        }

        // must be all digits
        const bool isNumeric = !line.empty() &&
            std::all_of(line.begin(), line.end(), [](unsigned char c) { return std::isdigit(c); });

        if (!isNumeric)
        {
            std::cout << "Invalid input." << std::endl;
            continue;
        }

        uint64_t problemNumber{};
        try
        {
            problemNumber = std::stoull(line);
        }
        catch (...)
        {
            std::cout << "Invalid input." << std::endl;
            continue;
        }

        if (problemNumber == 0)
        {
            runVerifyAll();
        }
        else
        {
            runSingle(problemNumber);
        }
    }

    return 0;
}

void Menu::runVerifyAll() const {
    setPrintEnabled(false);

    for (const auto& problem : problems())
    {
        runProblem(problem, PrintMode::verify);
    }
}

void Menu::runSingle(uint64_t problemNumber) const {
    const auto& allProblems = problems();

    const auto it = std::find_if(allProblems.begin(), allProblems.end(), [problemNumber](const Problem& problem)
        {
            return problem.number == problemNumber;
        });

    if (it == allProblems.end())
    {
        std::cout << "Problem " << problemNumber << " was not found." << std::endl;
        return;
    }

    setPrintEnabled(true);
    runProblem(*it, PrintMode::all);
}

void Menu::runProblem(const Problem& problem, PrintMode printMode) const {
    if (!problem.solution)
    {
        std::cout << "Problem " << problem.number << " has no solution function." << std::endl;
        return;
    }

    if (hasFlag(printMode, PrintMode::question))
    {
        std::cout << "Problem " << problem.number << ": " << problem.title << std::endl;
        std::cout << problem.body << std::endl;
    }

    if (!hasFlag(printMode, PrintMode::verify) && !hasFlag(printMode, PrintMode::solution))
    {
        return;
    }

    const auto result = problem.solution();

    if (hasFlag(printMode, PrintMode::verify))
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
