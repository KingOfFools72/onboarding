#pragma once
#include <atlbase.h>
#include <atlcom.h>

#include "CalculatorLib.h"

#import "ScalableCalculatorCOMEvents.tlb" raw_interfaces_only

using namespace ATL;
using namespace ScalableCalculatorCOMEventsLib;

class CCalculatorImpl;
typedef IDispEventImpl<0, CCalculatorImpl, &__uuidof(_ICalculatorEvents), &__uuidof(__ScalableCalculatorCOMEventsLib), 1, 0> CalcEventsImpl;

class CCalculatorImpl : public CalcEventsImpl
{
public:
	BEGIN_SINK_MAP(CCalculatorImpl)
		SINK_ENTRY_EX(0, __uuidof(_ICalculatorEvents), DISPID_ADD, OnAdd)
		SINK_ENTRY_EX(0, __uuidof(_ICalculatorEvents), DISPID_SUBTRACT, OnSubtract)
		SINK_ENTRY_EX(0, __uuidof(_ICalculatorEvents), DISPID_MULTIPLY, OnMultiply)
		SINK_ENTRY_EX(0, __uuidof(_ICalculatorEvents), DISPID_DIVIDE, OnDivide)
		SINK_ENTRY_EX(0, __uuidof(_ICalculatorEvents), DISPID_NOTHING, DoNothing)
	END_SINK_MAP();

	CCalculatorImpl();
	CCalculatorImpl(CComPtr<ICalculator>& source);

	HRESULT Subscribe();
	HRESULT Unsubscribe();

	LONGLONG GetResult(std::unique_ptr<NativeCalculator::IActionCreator> action, int lhs, int rhs);
	void __stdcall OnAdd(LONGLONG lhs, LONGLONG rhs, LONGLONG* res);
	void __stdcall OnSubtract(LONGLONG lhs, LONGLONG rhs, LONGLONG* res);
	void __stdcall OnMultiply(LONGLONG lhs, LONGLONG rhs, LONGLONG* res);
	void __stdcall OnDivide(LONGLONG lhs, LONGLONG rhs, LONGLONG* res);
	void __stdcall DoNothing(LONGLONG lhs, LONGLONG rhs, LONGLONG* res);

	void PrintAllLogMessages() const;
	void PrintAllResultNumbers() const;
	const std::vector<int>& GetAllComputations() const;
	~CCalculatorImpl();

private:
	bool m_isSubsribed = false;
	CComPtr<ICalculator> m_spCalcSource;
	CComPtr<IUnknown> m_spUnk;
	NativeCalculator::Calculator m_calc;
};