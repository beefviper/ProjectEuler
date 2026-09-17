// print.h
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#pragma once

#include <iostream>
#include <utility>

namespace ProjectEuler {

class ConditionalPrint {
public:
    void setEnabled(bool enabled);

    template <typename T>
    ConditionalPrint& operator<<(T&& value) {
        if (enabled_) {
            std::cout << std::forward<T>(value);
        }

        return *this;
    }

    ConditionalPrint& operator<<(std::ostream& (*manipulator)(std::ostream&));

private:
    bool enabled_{false};
};

extern ConditionalPrint print;

void setPrintEnabled(bool enabled);

} // namespace ProjectEuler
