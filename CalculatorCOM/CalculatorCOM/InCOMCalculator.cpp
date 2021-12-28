// InCOMCalculator.cpp : Implementation of CInCOMCalculator

#include "pch.h"
#include "InCOMCalculator.h"


// CInCOMCalculator

STDMETHODIMP CInCOMCalculator::Add(UINT a, UINT b, UINT* res)
{
	*res = calc->Add(a, b);
	return S_OK;
};

STDMETHODIMP CInCOMCalculator::Sub(UINT a, UINT b, UINT* res)
{
	*res = calc->Sub(a, b);
	return S_OK;
};

STDMETHODIMP CInCOMCalculator::Div(UINT a, UINT b, UINT* res)
{
	try
	{
		*res = calc->Div(a, b);
		return S_OK;
	}
	catch (...)
	{
		return E_FAIL;
	}
};

STDMETHODIMP CInCOMCalculator::Mul(UINT a, UINT b, UINT* res)
{
	*res = calc->Mul(a, b);
	return S_OK;
};