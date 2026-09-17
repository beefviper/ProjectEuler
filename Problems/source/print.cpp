// print.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#include "print.h"

#include <iostream>
#include <ostream>

namespace ProjectEuler {

ConditionalPrint print;

void ConditionalPrint::setEnabled(bool enabled) {
    enabled_ = enabled;
}

ConditionalPrint& ConditionalPrint::operator<<(std::ostream& (*manipulator)(std::ostream&)) {
    if (enabled_) {
        manipulator(std::cout);
    }

    return *this;
}

void setPrintEnabled(bool enabled) {
    print.setEnabled(enabled);
}

} // namespace ProjectEuler