#include "pch.h"
#include "Actions.h"

#include <iostream>

int NullAction::calculate() {
	calcRes = INT_MAX;
	return calcRes;
}

void NullAction::write(std::string& log) {
	std::cout << log << std::endl;
}

int Add::calculate() {
	calcRes = lhs_ + rhs_;
	return calcRes;
}

void Add::write(std::string& log) {
	std::cout << log << std::endl;
}

int Sub::calculate() {
	calcRes = lhs_ - rhs_;
	return calcRes;
}

void Sub::write(std::string& log) {
	std::cout << log << std::endl;
}

int Div::calculate() {
	if (rhs_ == 0)
	{
		throw std::invalid_argument("Denominator mustn't be a zero!");
	}
	calcRes = lhs_ / rhs_;
	return calcRes;
}

void Div::write(std::string& log) {
	std::cout << log << std::endl;
}

int Mul::calculate() {
	calcRes = lhs_ * rhs_;
	return calcRes;
}

void Mul::write(std::string& log) {
	std::cout << log << std::endl;
}