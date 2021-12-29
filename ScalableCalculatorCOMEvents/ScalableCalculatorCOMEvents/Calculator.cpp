// Calculator.cpp : Implementation of CCalculator

#include "pch.h"
#include "Calculator.h"

// CCalculator

STDMETHODIMP CCalculator::Compute(CHAR action, LONGLONG lhs, LONGLONG rhs, LONGLONG* res)
{
	if (action == '+')
	{
		return Fire_Event(DISPID_ADD, lhs, rhs, res);
	}
	else if (action == '-')
	{
		return Fire_Event(DISPID_SUBTRACT, lhs, rhs, res);
	}
	else if (action == '*')
	{
		return Fire_Event(DISPID_MULTIPLY, lhs, rhs, res);
	}
	else if (action == '/')
	{
		return Fire_Event(DISPID_DIVIDE, lhs, rhs, res);
	}
	else {
		return Fire_Event(DISPID_NOTHING, lhs, rhs, res);
	}
}
