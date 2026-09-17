// menu.h
// Project Euler Problems
// author: beefviper
// date: Sept 17, 2026

#pragma once

#include "problems.h"

#include <cstdint>

namespace ProjectEuler {

enum class PrintMode : uint32_t {
    none = 0,
    verify = 1 << 0,
    question = 1 << 1,
    solution = 1 << 2,
    all = verify | question | solution
};

class Menu {
public:
    Menu();
    int run() const;

private:
    void runProblem(const Problem& problem, PrintMode printMode) const;
    void runVerifyAll() const;
    void runSingle(uint64_t problemNumber) const;
};

} // namespace ProjectEuler
