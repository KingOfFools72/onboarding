// Calculator.cpp : Implementation of CCalculator

#include "pch.h"
#include "Calculator.h"

// CCalculator

CCalculator::CCalculator() { };

HRESULT CCalculator::FinalConstruct()
{
	return S_OK;
}

void CCalculator::FinalRelease() { };

STDMETHODIMP CCalculator::Compute(const CHAR action, const LONGLONG lhs, const LONGLONG rhs)
{
	if (action == '+')
	{
		return Fire_Event(EVID_ADD, lhs, rhs);
	}
	else if (action == '-')
	{
		return Fire_Event(EVID_SUBTRACT, lhs, rhs);
	}
	else if (action == '*')
	{
		return Fire_Event(EVID_MULTIPLY, lhs, rhs);
	}
	else if (action == '/')
	{
		return Fire_Event(EVID_DIVIDE, lhs, rhs);
	}
	else
	{
		return Fire_Event(EVID_NOTHING, lhs, rhs);
	}
}
