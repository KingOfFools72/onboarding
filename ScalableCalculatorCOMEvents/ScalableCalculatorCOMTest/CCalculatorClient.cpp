#include "pch.h"
#include "CCalculatorClient.h"
#include "CalculatorLib.h"
#include "CCalculatorImpl.h"

CCalculatorClient::CCalculatorClient(CComPtr<ICalculator> source)
	: m_spImpl(std::make_unique<CCalculatorImpl>(source)){}

CCalculatorClient::~CCalculatorClient() = default;

CCalculatorClient::CCalculatorClient(CCalculatorClient&& other)
{
	m_spImpl.swap(other.m_spImpl);
}

CCalculatorClient& CCalculatorClient::operator=(CCalculatorClient&& other)
{
	m_spImpl.reset(other.m_spImpl.get());
	return *this;
}

void CCalculatorClient::PrintAllLogMessages() const
{
	m_spImpl->PrintAllLogMessages();
}

void CCalculatorClient::PrintAllResultNumbers() const
{
	m_spImpl->PrintAllResultNumbers();
}

const std::vector<int>& CCalculatorClient::GetAllComputations() const
{
	return m_spImpl->GetAllComputations();
}

void CCalculatorClient::OnAdd(const LONGLONG lhs, const LONGLONG rhs)
{
	m_spImpl->OnAdd(lhs, rhs);
}

void CCalculatorClient::OnSubtract(const LONGLONG lhs, const LONGLONG rhs)
{
	m_spImpl->OnSubtract(lhs, rhs);
}

void CCalculatorClient::OnMultiply(const LONGLONG lhs, const LONGLONG rhs)
{
	m_spImpl->OnMultiply(lhs, rhs);
}

void CCalculatorClient::OnDivide(const LONGLONG lhs, const LONGLONG rhs)
{
	m_spImpl->OnDivide(lhs, rhs);
}

void CCalculatorClient::DoNothing(const LONGLONG lhs, const LONGLONG rhs)
{
	m_spImpl->DoNothing(lhs, rhs);
}