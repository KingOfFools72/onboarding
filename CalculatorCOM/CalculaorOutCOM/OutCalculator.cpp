// OutCalculator.cpp : Implementation of COutCalculator

#include "pch.h"
#include "OutCalculator.h"


// COutCalculator

STDMETHODIMP COutCalculator::Add(UINT a, UINT b, UINT* res)
{
	*res = calc->Add(a, b);
	return S_OK;
};

STDMETHODIMP COutCalculator::Sub(UINT a, UINT b, UINT* res)
{
	*res = calc->Sub(a, b);
	return S_OK;
};

STDMETHODIMP COutCalculator::Div(UINT a, UINT b, UINT* res)
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

STDMETHODIMP COutCalculator::Mul(UINT a, UINT b, UINT* res)
{
	*res = calc->Mul(a, b);
	return S_OK;
};