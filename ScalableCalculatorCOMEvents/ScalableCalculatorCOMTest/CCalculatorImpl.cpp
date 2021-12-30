#include "pch.h"
#include "CCalculatorImpl.h"

CCalculatorImpl::CCalculatorImpl(CComPtr<ICalculator> source)
	: m_isSubsribed(false), m_spCalcSource(source)
{
	if (m_spCalcSource == nullptr) { throw std::invalid_argument("Source is null"); }
	Subscribe();
	if (!m_isSubsribed) { throw std::exception("Can't Subscribe"); }
}

CCalculatorImpl::~CCalculatorImpl()
{
	if (m_isSubsribed)	{
		Unsubscribe();
	}
}

HRESULT CCalculatorImpl::Subscribe()
{
	const HRESULT hr = DispEventAdvise(m_spCalcSource, &__uuidof(_ICalculatorEvents));

	if (SUCCEEDED(hr))	{
		m_isSubsribed = true;
	}
	return hr;
}

HRESULT CCalculatorImpl::Unsubscribe()
{
	auto hr = DispEventUnadvise(m_spCalcSource, &__uuidof(_ICalculatorEvents));

	if (SUCCEEDED(hr))	{
		m_isSubsribed = false;
	}

	return hr;
}

LONGLONG CCalculatorImpl::GetResult(std::unique_ptr<NativeCalculator::IActionCreator> action)
{
	m_calc.AddCommand(NativeCalculator::CalculatorCommand(std::move(action)));
	m_calc.Compute();
	return m_calc.GetResultNumbers().back();
}

void __stdcall CCalculatorImpl::OnAdd(const LONGLONG lhs, const LONGLONG rhs)
{
	GetResult(std::make_unique<NativeCalculator::AddCreator>(lhs, rhs));
}

void __stdcall CCalculatorImpl::OnSubtract(const LONGLONG lhs, const LONGLONG rhs)
{
	GetResult(std::make_unique<NativeCalculator::SubCreator>(lhs, rhs));
}

void __stdcall CCalculatorImpl::OnMultiply(const LONGLONG lhs, const LONGLONG rhs)
{
	GetResult(std::make_unique<NativeCalculator::MulCreator>(lhs, rhs));
}

void __stdcall CCalculatorImpl::OnDivide(const LONGLONG lhs, const LONGLONG rhs)
{
	GetResult(std::make_unique<NativeCalculator::DivCreator>(lhs, rhs));
}

void __stdcall CCalculatorImpl::DoNothing(const LONGLONG lhs, const LONGLONG rhs)
{
	GetResult(std::make_unique<NativeCalculator::NullCreator>(lhs, rhs));
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
