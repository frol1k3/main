#pragma once
#include <iostream>

template<typename NumericType>NumericType
sum(NumericType x, NumericType y) {
    static_assert(std::is_arithmetic<NumericType>::value, "NumericType не является числом");
    return x + y;
};

template<typename NumericType>NumericType
raz(NumericType x, NumericType y) {
    static_assert(std::is_arithmetic<NumericType>::value, "NumericType не является числом");
    return x - y;
}