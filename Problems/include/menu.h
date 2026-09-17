// menu.h
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#pragma once

#include "problems.h"

#include <cstdint>

namespace ProjectEuler {

enum class PrintMode : uint32_t {
    none     = 0,
    verify   = 1 << 0,
    question = 1 << 1,
    solution = 1 << 2,
    all      = verify | question | solution
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

} // namespace ProjectEuler
