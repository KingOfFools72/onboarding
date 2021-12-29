#pragma once

#include <atlbase.h>
#include <atlcom.h>
#include <iostream>
#include <memory>
#include <vector>

#import "ScalableCalculatorCOMEvents.tlb" raw_interfaces_only

using namespace ATL;
using namespace ScalableCalculatorCOMEventsLib;

class CCalculatorImpl;

class CCalculatorClient
{
public:
	CCalculatorClient(CComPtr<ICalculator>& source);
	CCalculatorClient(const CCalculatorClient& other) = delete;
	CCalculatorClient& operator=(const CCalculatorClient& other) = delete;
	CCalculatorClient(CCalculatorClient&& other);
	CCalculatorClient& operator=(CCalculatorClient&& other);
	~CCalculatorClient();

	HRESULT Subscribe();
	HRESULT Unsubscribe();
	void PrintAllLogMessages() const;
	void PrintAllResultNumbers() const;
	const std::vector<int>& GetAllComputations() const;

private:
	std::unique_ptr<CCalculatorImpl> m_spImpl;

	void OnAdd(LONGLONG lhs, LONGLONG rhs, LONGLONG* res);
	void OnSubtract(LONGLONG lhs, LONGLONG rhs, LONGLONG* res);
	void OnMultiply(LONGLONG lhs, LONGLONG rhs, LONGLONG* res);
	void OnDivide(LONGLONG lhs, LONGLONG rhs, LONGLONG* res);
	void DoNothing(LONGLONG lhs, LONGLONG rhs, LONGLONG* res);
};