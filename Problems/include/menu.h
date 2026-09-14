#pragma once

#include "Problems.h"

class Menu {
public:
    explicit Menu(uint64_t problemNumber = 0);
    int run() const;

private:
    uint64_t problemNumber_{};

    static void runProblem(const Problem& problem);
};
