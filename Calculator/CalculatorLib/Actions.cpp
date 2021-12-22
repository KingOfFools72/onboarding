#include "pch.h"
#include "Actions.h"

#include <iostream>

int NullAction::calculate(int a, int b) {
	calcRes = INT_MAX;
	return calcRes;
}

void NullAction::write(std::string& log) {
	std::cout << log << std::endl;
}

int Add::calculate(int a, int b) {
	calcRes = a + b;
	return calcRes;
}

void Add::write(std::string& log) {
	std::cout << log << std::endl;
}

int Sub::calculate(int a, int b) {
	calcRes = a - b;
	return calcRes;
}

void Sub::write(std::string& log) {
	std::cout << log << std::endl;
}

int Div::calculate(int a, int b) {
	calcRes = a / b;
	return calcRes;
}

void Div::write(std::string& log) {
	std::cout << log << std::endl;
}

int Mul::calculate(int a, int b) {
	calcRes = a * b;
	return calcRes;
}

void Mul::write(std::string& log) {
	std::cout << log << std::endl;
}