// color.cpp
// Project Euler Problems
// author: beefviper
// date: Sept 17, 2026

#include "color.h"

#ifdef _WIN32
#include <windows.h>
#endif

#include <ostream>

namespace ProjectEuler {

std::ostream& operator<<(std::ostream& os, Color color) {
    switch (color)
    {
    case Color::Default:       return os << "\033[0m";
    case Color::Red:           return os << "\033[31m";
    case Color::Green:         return os << "\033[32m";
    case Color::Yellow:        return os << "\033[33m";
    case Color::Blue:          return os << "\033[34m";
    case Color::Magenta:       return os << "\033[35m";
    case Color::Cyan:          return os << "\033[36m";
    case Color::White:         return os << "\033[37m";
    case Color::BrightRed:     return os << "\033[91m";
    case Color::BrightGreen:   return os << "\033[92m";
    case Color::BrightYellow:  return os << "\033[93m";
    case Color::BrightBlue:    return os << "\033[94m";
    case Color::BrightMagenta: return os << "\033[95m";
    case Color::BrightCyan:    return os << "\033[96m";
    case Color::BrightWhite:   return os << "\033[97m";
    }
    return os;
}

void enableAnsiColors() {
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
    {
        return;
    }

    DWORD mode{};
    if (!GetConsoleMode(hOut, &mode))
    {
        return;
    }

    SetConsoleMode(hOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif
    // No-op elsewhere; modern Linux/macOS terminals support ANSI
    // escape sequences natively without any setup.
}

} // namespace ProjectEuler
