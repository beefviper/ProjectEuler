// color.h
// Project Euler Problems
// author: beefviper
// date: Sept 17, 2026

#pragma once

#include <ostream>

namespace ProjectEuler {

enum class Color {
    Default,
    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
    White,
    BrightRed,
    BrightGreen,
    BrightYellow,
    BrightBlue,
    BrightMagenta,
    BrightCyan,
    BrightWhite
};

// Usage: std::cout << Color::BrightGreen << "text" << Color::Default;
std::ostream& operator<<(std::ostream& os, Color color);

// Enables ANSI escape sequence interpretation on Windows consoles
// (build 1511+). No-op on platforms where it isn't needed.
void enableAnsiColors();

} // namespace ProjectEuler
