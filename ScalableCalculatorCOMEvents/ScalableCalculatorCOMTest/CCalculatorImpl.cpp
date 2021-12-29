#include "pch.h"
#include "CCalculatorImpl.h"

CCalculatorImpl::CCalculatorImpl() {}

CCalculatorImpl::CCalculatorImpl(CComPtr<ICalculator>& source)
	: m_spCalcSource(source)
{
}

HRESULT CCalculatorImpl::Subscribe()
{
	HRESULT hr = m_spCalcSource.QueryInterface(&m_spUnk);
	hr = DispEventAdvise(m_spUnk, &__uuidof(_ICalculatorEvents));

	if (SUCCEEDED(hr))
	{
		m_isSubsribed = true;
	}
	return hr;
}

HRESULT CCalculatorImpl::Unsubscribe()
{
	auto hr = DispEventUnadvise(m_spUnk, &__uuidof(_ICalculatorEvents));

	if (SUCCEEDED(hr))
	{
		m_isSubsribed = false;
	}

	return hr;
}

LONGLONG CCalculatorImpl::GetResult(std::unique_ptr<NativeCalculator::IActionCreator> action, int lhs, int rhs)
{
	m_calc.AddCommand(NativeCalculator::CalculatorCommand(std::move(action)));
	m_calc.Compute();
	return m_calc.GetResultNumbers().back();
}

void __stdcall CCalculatorImpl::OnAdd(LONGLONG lhs, LONGLONG rhs, LONGLONG* res)
{
	//NativeCalculator::AddCreator ad(lhs, rhs);
	*res = GetResult(std::make_unique<NativeCalculator::AddCreator>(lhs, rhs), lhs, rhs);
}

void __stdcall CCalculatorImpl::OnSubtract(LONGLONG lhs, LONGLONG rhs, LONGLONG* res)
{
	*res = GetResult(std::make_unique<NativeCalculator::SubCreator>(lhs, rhs), lhs, rhs);
}

void __stdcall CCalculatorImpl::OnMultiply(LONGLONG lhs, LONGLONG rhs, LONGLONG* res)
{
	*res = GetResult(std::make_unique<NativeCalculator::MulCreator>(lhs, rhs), lhs, rhs);
}

void __stdcall CCalculatorImpl::OnDivide(LONGLONG lhs, LONGLONG rhs, LONGLONG* res)
{
	*res = GetResult(std::make_unique<NativeCalculator::DivCreator>(lhs, rhs), lhs, rhs);
}

void __stdcall CCalculatorImpl::DoNothing(LONGLONG lhs, LONGLONG rhs, LONGLONG* res)
{
	*res = GetResult(std::make_unique<NativeCalculator::NullCreator>(lhs, rhs), lhs, rhs);
}

void CCalculatorImpl::PrintAllLogMessages() const
{
	m_calc.PrintResultMessages();
}

void CCalculatorImpl::PrintAllResultNumbers() const
{
	m_calc.PrintResultNumbers();
}

const std::vector<int>& CCalculatorImpl::GetAllComputations() const
{
	return m_calc.GetResultNumbers();
}

CCalculatorImpl::~CCalculatorImpl()
{
	if (m_isSubsribed)
	{
		Unsubscribe();
	}
}
