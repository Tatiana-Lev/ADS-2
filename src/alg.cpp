// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cstdint>
#include <iostream>
#include <cmath>

double pown(double value, uint16_t n) {
	if (n == 0) {
		return 1.0;
	}
	double result = 1.0;
	if (value == 0 && n == 0) {
		return 1.0;
	} 
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
		return 0;
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
	if (factorial == 0 || std::isnan(exponent) || std::isinf(exponent)) {
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
	double cur_t = 1.0;
	for (uint16_t n = 0; n < count; ++n) {
		sum += cur_t;

		if (std::abs(cur_t) < 1e-15) {
			break;
		}
		cur_t *= x / (n + 1);
	}
	return sum;
}

double sinn(double x, uint16_t count) {
	if (std::isnan(x)) {
		return std::nan("");
	}
	double sum = 0.0;
	double cur_t = x;
	for (uint16_t k = 0; k < count; ++k) {
		sum += cur_t;
		if (std::abs(cur_t) < 1e-15) {
			break;
		}
		double next_t = cur_t * x * x / ((2 * k + 2) * (2 * k + 3));
		cur_t = -next_t;
	}
	return sum;
}

double cosn(double x, uint16_t count) {
	if (std::isnan(x)) {
		return std::nan("");
	}
	double sum = 0.0;
	double cur_t = 1.0;
	for (uint16_t k = 0; k < count; ++k) {
		sum += cur_t;
		if (std::abs(cur_t) < 1e-15) {
			break;
		}
		double next_t = cur_t * x * x / ((2 * k + 1) * (2 * k + 2));
		cur_t = -next_t;
	}
	return sum;
}
