// menu.h
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#pragma once

#include "problems.h"

enum class PrintMode : uint32_t {
    none     = 0,
    verify   = 1 << 0,
    question = 1 << 1,
    solution = 1 << 2,
    answer   = 1 << 3,
    all      = verify | question | solution | answer
};

[[nodiscard]] constexpr PrintMode operator|(PrintMode left, PrintMode right) {
    return static_cast<PrintMode>(
        static_cast<uint32_t>(left) | static_cast<uint32_t>(right));
}

[[nodiscard]] constexpr PrintMode operator&(PrintMode left, PrintMode right) {
    return static_cast<PrintMode>(
        static_cast<uint32_t>(left) & static_cast<uint32_t>(right));
}

constexpr PrintMode& operator|=(PrintMode& left, PrintMode right) {
    left = left | right;
    return left;
}

[[nodiscard]] constexpr bool hasFlag(PrintMode mode, PrintMode flag) {
    return static_cast<uint32_t>(mode & flag) != 0;
}

class Menu {
public:
    explicit Menu(uint64_t problemNumber = 0, PrintMode printMode = PrintMode::verify);
    int run() const;

private:
    uint64_t problemNumber_{};
    PrintMode printMode_{};

    void runProblem(const Problem& problem) const;
};
