// menu.h
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#pragma once

#include "problems.h"

enum class PrintMode {
    verify,
    question,
    statements,
    both
};

class Menu {
public:
    explicit Menu(uint64_t problemNumber = 0, PrintMode printMode = PrintMode::verify);
    int run() const;

private:
    uint64_t problemNumber_{};
    PrintMode printMode_{};

    void runProblem(const Problem& problem) const;
};
