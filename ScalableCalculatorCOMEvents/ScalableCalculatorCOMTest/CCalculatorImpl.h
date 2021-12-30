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

	CCalculatorImpl(CComPtr<ICalculator> source);

	LONGLONG GetResult(std::unique_ptr<NativeCalculator::IActionCreator> action);
	void __stdcall OnAdd(const LONGLONG lhs, const LONGLONG rhs);
	void __stdcall OnSubtract(const LONGLONG lhs, const LONGLONG rhs);
	void __stdcall OnMultiply(const LONGLONG lhs, const LONGLONG rhs);
	void __stdcall OnDivide(const LONGLONG lhs, const LONGLONG rhs);
	void __stdcall DoNothing(const LONGLONG lhs, const LONGLONG rhs);

	void PrintAllLogMessages() const;
	void PrintAllResultNumbers() const;
	const std::vector<int>& GetAllComputations() const;
	~CCalculatorImpl();

private:
	bool m_isSubsribed;
	CComPtr<ICalculator> m_spCalcSource;
	NativeCalculator::Calculator m_calc;

	CComQIPtr<ICalculator> pCalcSource;

	HRESULT Subscribe();
	HRESULT Unsubscribe();
};