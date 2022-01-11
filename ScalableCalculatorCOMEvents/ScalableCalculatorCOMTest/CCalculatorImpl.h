#pragma once
#include <atlbase.h>
#include <atlcom.h>

#include "CalculatorLib.h"

#import "ScalableCalculatorCOMEvents.tlb" raw_interfaces_only

using namespace ATL;
using namespace ScalableCalculatorCOMLib;

class CCalculatorEventsImpl;
typedef IDispEventImpl<0, CCalculatorEventsImpl, &__uuidof(_ICalculatorEvents), &__uuidof(__ScalableCalculatorCOMLib), 1, 0> CalcEventsImpl;

class CCalculatorEventsImpl : public CalcEventsImpl
{
public:
	BEGIN_SINK_MAP(CCalculatorEventsImpl)
		SINK_ENTRY_EX(0, __uuidof(_ICalculatorEvents), EVID_ADD, OnAdd)
		SINK_ENTRY_EX(0, __uuidof(_ICalculatorEvents), EVID_SUBTRACT, OnSubtract)
		SINK_ENTRY_EX(0, __uuidof(_ICalculatorEvents), EVID_MULTIPLY, OnMultiply)
		SINK_ENTRY_EX(0, __uuidof(_ICalculatorEvents), EVID_DIVIDE, OnDivide)
		SINK_ENTRY_EX(0, __uuidof(_ICalculatorEvents), EVID_NOTHING, DoNothing)
	END_SINK_MAP();

	CCalculatorEventsImpl(CComPtr<ICalculatorEv> source);

	LONGLONG GetResult(std::unique_ptr<NativeCalculator::IActionCreator> action);
	void __stdcall OnAdd(const LONGLONG lhs, const LONGLONG rhs);
	void __stdcall OnSubtract(const LONGLONG lhs, const LONGLONG rhs);
	void __stdcall OnMultiply(const LONGLONG lhs, const LONGLONG rhs);
	void __stdcall OnDivide(const LONGLONG lhs, const LONGLONG rhs);
	void __stdcall DoNothing(const LONGLONG lhs, const LONGLONG rhs);

	void PrintAllLogMessages() const;
	void PrintAllResultNumbers() const;
	const std::vector<int>& GetAllComputations() const;
	~CCalculatorEventsImpl();

private:
	CComPtr<ICalculatorEv> m_spCalcSource;
	NativeCalculator::Calculator m_calc;

	void Subscribe();
	void Unsubscribe();
};