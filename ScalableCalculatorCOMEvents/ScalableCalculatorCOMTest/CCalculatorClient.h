#pragma once

#include <atlbase.h>
#include <atlcom.h>
#include <memory>
#include <vector>

#import "ScalableCalculatorCOMEvents.tlb" raw_interfaces_only

using namespace ATL;
using namespace ScalableCalculatorCOMEventsLib;

class CCalculatorImpl;

class CCalculatorClient
{
public:
	CCalculatorClient(CComPtr<ICalculator> source);
	CCalculatorClient(const CCalculatorClient& other) = delete;
	CCalculatorClient& operator=(const CCalculatorClient& other) = delete;
	CCalculatorClient(CCalculatorClient&& other);
	CCalculatorClient& operator=(CCalculatorClient&& other);
	~CCalculatorClient();

	void PrintAllLogMessages() const;
	void PrintAllResultNumbers() const;
	const std::vector<int>& GetAllComputations() const;

private:
	std::unique_ptr<CCalculatorImpl> m_spImpl;

	void OnAdd(const LONGLONG lhs, const LONGLONG rhs);
	void OnSubtract(const LONGLONG lhs, const LONGLONG rhs);
	void OnMultiply(const LONGLONG lhs, const LONGLONG rhs);
	void OnDivide(const LONGLONG lhs, const LONGLONG rhs);
	void DoNothing(const LONGLONG lhs, const LONGLONG rhs);
};