#include "pch.h"
#include "CCalculatorClient.h"
#include "CalculatorLib.h"
#include "CCalculatorImpl.h"

CCalculatorClient::CCalculatorClient(CComPtr<ICalculator>& source)
	: m_spImpl(std::make_unique<CCalculatorImpl>(source)) {}

CCalculatorClient::CCalculatorClient(CCalculatorClient&& other)
{
	m_spImpl.swap(other.m_spImpl);
}

CCalculatorClient& CCalculatorClient::operator=(CCalculatorClient&& other)
{
	m_spImpl.reset(other.m_spImpl.get());
	return *this;
}

HRESULT CCalculatorClient::Subscribe()
{
	return m_spImpl->Subscribe();
}

HRESULT CCalculatorClient::Unsubscribe()
{
	return m_spImpl->Unsubscribe();
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

void CCalculatorClient::OnAdd(LONGLONG lhs, LONGLONG rhs, LONGLONG* res)
{
	m_spImpl->OnAdd(lhs, rhs, res);
}

void CCalculatorClient::OnSubtract(LONGLONG lhs, LONGLONG rhs, LONGLONG* res)
{
	m_spImpl->OnSubtract(lhs, rhs, res);
}

void CCalculatorClient::OnMultiply(LONGLONG lhs, LONGLONG rhs, LONGLONG* res)
{
	m_spImpl->OnMultiply(lhs, rhs, res);
}

void CCalculatorClient::OnDivide(LONGLONG lhs, LONGLONG rhs, LONGLONG* res)
{
	m_spImpl->OnDivide(lhs, rhs, res);
}

void CCalculatorClient::DoNothing(LONGLONG lhs, LONGLONG rhs, LONGLONG* res)
{
	m_spImpl->DoNothing(lhs, rhs, res);
}

CCalculatorClient::~CCalculatorClient() = default;