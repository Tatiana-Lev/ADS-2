// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cstdint>
#include <iostream>
#include <cmath>




double pown(double value, uint16_t n) {
    if (n == 0) {
        return 1.0;
    }

    if (value == 0 && n == 0) {
        return 1.0;
    } 

    double result = 1.0; 

    for (uint16_t i = 0; i < n; i++) {

        result = result * value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    if (n == 0) {
        return 1;
    }

    if (n > 20) {
        return UINT64_MAX;
    }

    uint64_t result = 1;
   

    for (int i = 1; i <= n; i++) {

        result = result * i;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    
    double exponent = pown(x, n);
    uint64_t factorial = fact(n);
    
    if (factorial == 0 || std::isnan(exponent) || std::isnig(exponent)) {
        return std::nan("");
    }
    
    return exponent/static_cast<double>(factorial);

}

double expn(double x, uint16_t count) {
    
    if (std::isnan(x))
    {
        return std::nan("");
    }
    
    double sum = 0.0;

    for (uint16_t n = 0; n < count; ++n) {
        double exponent = pown(x, n);
        uint64_t factorial = fact(n);

        if (factorial == 0 || std::isnan(exponent) || std::isinf(exponent)) {
            return std::nan("Error");
        }
        sum += exponent / static_cast<double>(factorial);
    }
    return sum;
}

double sinn(double x, uint16_t count) {

    if (std::isnan(x)) {
        return std::nan("");
    }
    double sum = 0.0;

    for (uint16_t k = 0; k < count; ++k) {

        int exp = 2 * k + 1;
        double exponent = pown(x, exp);
        uint64_t factorial = fact(exp);
        
        if (factorial == 0 || std::isnan(exponent) || std::isinf(exponent)) {
            return std::nan("Error");
  
        }

        double sign;
        if (k % 2 == 0) {
            sign = 1.0;
        }
        else {
            sign = -1.0;
        }
        sum += sign * exponent / static_cast<double>(factorial);
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    
    if (std::isnan(x)) {
        return std::nan("");
    }

    double sum = 0.0;

    for (uint16_t k = 0; k < count; ++k) {

        int exp = 2 * k;
        double exponent = pown(x, exp);
        uint64_t factorial = fact(exp);
        
        if (factorial == 0 || std::isnan(exponent) || std::isinf(exponent)) {
            return std::nan("Error");
        }
        double sign;
        if (k % 2 == 0) {
            sign = 1.0;
        }
        else {
            sign = -1.0;
        }
        sum += sign * exponent / static_cast<double>(factorial);
    }
    return sum;
}
