#include "pch.h"
#include "Calculator.h"

#include <iostream>

int Calculator::Add(int a, int b)
{
	return a + b;
}

int Calculator::Sub(int a, int b)
{
	return a - b;
}

int Calculator::Div(int a, int b)
{
	if (b == 0) { throw std::invalid_argument("Denominator mustn't be a zero!"); };
	return a / b;
}

int Calculator::Mul(int a, int b)
{
	return a * b;
}