// flags.h
// Project Euler Problems
// author: beefviper
// date: Sept 14, 2026

#pragma once

#include <concepts>
#include <type_traits>

template<typename T>
concept FlagEnum = std::is_scoped_enum_v<T>
    && std::unsigned_integral<std::underlying_type_t<T>>;

template<FlagEnum T>
[[nodiscard]] constexpr T operator|(T left, T right) {
    using U = std::underlying_type_t<T>;
    return static_cast<T>(static_cast<U>(left) | static_cast<U>(right));
}

template<FlagEnum T>
[[nodiscard]] constexpr T operator&(T left, T right) {
    using U = std::underlying_type_t<T>;
    return static_cast<T>(static_cast<U>(left) & static_cast<U>(right));
}

template<FlagEnum T>
constexpr T& operator|=(T& left, T right) {
    left = left | right;
    return left;
}

template<FlagEnum T>
[[nodiscard]] constexpr bool hasFlag(T mode, T flag) {
    using U = std::underlying_type_t<T>;
    return (static_cast<U>(mode) & static_cast<U>(flag)) != 0;
}
