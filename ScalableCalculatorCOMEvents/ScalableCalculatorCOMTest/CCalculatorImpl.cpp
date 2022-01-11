#include "pch.h"
#include "CCalculatorImpl.h"

#include <system_error>

CCalculatorEventsImpl::CCalculatorEventsImpl(CComPtr<ICalculatorEv> source)
	: m_spCalcSource(source)
{
	if (m_spCalcSource == nullptr)
	{
		throw std::invalid_argument("Source is null");
	}

	Subscribe();

}

CCalculatorEventsImpl::~CCalculatorEventsImpl()
{
	Unsubscribe();
}

void CCalculatorEventsImpl::Subscribe()
{
	const HRESULT hr = DispEventAdvise(m_spCalcSource, &__uuidof(_ICalculatorEvents));
	if (FAILED(hr))
	{
		throw std::exception("Can't Subscribe" + hr);
	}
}

void CCalculatorEventsImpl::Unsubscribe()
{
	auto hr = DispEventUnadvise(m_spCalcSource, &__uuidof(_ICalculatorEvents));
}

LONGLONG CCalculatorEventsImpl::GetResult(std::unique_ptr<NativeCalculator::IActionCreator> action)
{
	m_calc.AddCommand(NativeCalculator::CalculatorCommand(std::move(action)));
	m_calc.Compute();
	return m_calc.GetResultNumbers().back();
}

void __stdcall CCalculatorEventsImpl::OnAdd(const LONGLONG lhs, const LONGLONG rhs)
{
	GetResult(std::make_unique<NativeCalculator::AddCreator>(lhs, rhs));
}

void __stdcall CCalculatorEventsImpl::OnSubtract(const LONGLONG lhs, const LONGLONG rhs)
{
	GetResult(std::make_unique<NativeCalculator::SubCreator>(lhs, rhs));
}

void __stdcall CCalculatorEventsImpl::OnMultiply(const LONGLONG lhs, const LONGLONG rhs)
{
	GetResult(std::make_unique<NativeCalculator::MulCreator>(lhs, rhs));
}

void __stdcall CCalculatorEventsImpl::OnDivide(const LONGLONG lhs, const LONGLONG rhs)
{
	GetResult(std::make_unique<NativeCalculator::DivCreator>(lhs, rhs));
}

void __stdcall CCalculatorEventsImpl::DoNothing(const LONGLONG lhs, const LONGLONG rhs)
{
	GetResult(std::make_unique<NativeCalculator::NullCreator>(lhs, rhs));
}

void CCalculatorEventsImpl::PrintAllLogMessages() const
{
	m_calc.PrintResultMessages();
}

void CCalculatorEventsImpl::PrintAllResultNumbers() const
{
	m_calc.PrintResultNumbers();
}

const std::vector<int>& CCalculatorEventsImpl::GetAllComputations() const
{
	return m_calc.GetResultNumbers();
}
