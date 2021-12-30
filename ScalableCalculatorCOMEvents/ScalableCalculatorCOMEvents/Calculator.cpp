// Calculator.cpp : Implementation of CCalculator

#include "pch.h"
#include "Calculator.h"

// CCalculator

STDMETHODIMP CCalculator::Compute(const CHAR action, const LONGLONG lhs, const LONGLONG rhs)
{
	if (action == '+')
	{
		return Fire_Event(DISPID_ADD, lhs, rhs);
	}
	else if (action == '-')
	{
		return Fire_Event(DISPID_SUBTRACT, lhs, rhs);
	}
	else if (action == '*')
	{
		return Fire_Event(DISPID_MULTIPLY, lhs, rhs);
	}
	else if (action == '/')
	{
		return Fire_Event(DISPID_DIVIDE, lhs, rhs);
	}
	else {
		return Fire_Event(DISPID_NOTHING, lhs, rhs);
	}
}
