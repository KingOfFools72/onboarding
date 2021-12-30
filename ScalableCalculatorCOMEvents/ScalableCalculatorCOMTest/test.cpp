#include "pch.h"

#include "CCalculatorClient.h"

CComModule _Module;
extern __declspec(selectany) CAtlModule* _pAtlModule = &_Module;

CComPtr<ICalculator> g_spSource;

TEST(calculator_methods_test, add)
{
	CCalculatorClient client(g_spSource);
	g_spSource->Compute('+', 4, 19);
	std::vector<int> expected = { 23 };
	ASSERT_EQ(client.GetAllComputations(), expected);

	g_spSource->Compute('+', 10, -20);
	expected.push_back(-10);
	ASSERT_EQ(client.GetAllComputations(), expected);

	g_spSource->Compute('+', -10, -20);
	expected.push_back(-30);
	ASSERT_EQ(client.GetAllComputations(), expected);

	g_spSource->Compute('+', 10, -10);
	expected.push_back(0);
	ASSERT_EQ(client.GetAllComputations(), expected);
}

TEST(calculator_methods_test, subtract)
{
	CCalculatorClient client(g_spSource);
	g_spSource->Compute('-', 4, 19);
	std::vector<int> expected = { -15 };
	ASSERT_EQ(client.GetAllComputations(), expected);

	g_spSource->Compute('-', 10, -20);
	expected.push_back(30);
	ASSERT_EQ(client.GetAllComputations(), expected);

	g_spSource->Compute('-', -10, -20);
	expected.push_back(10);
	ASSERT_EQ(client.GetAllComputations(), expected);

	g_spSource->Compute('-', 10, -10);
	expected.push_back(20);
	ASSERT_EQ(client.GetAllComputations(), expected);
}

TEST(calculator_methods_test, multiply)
{
	CCalculatorClient client(g_spSource);
	g_spSource->Compute('*', 4, 19);
	std::vector<int> expected = { 76 };
	ASSERT_EQ(client.GetAllComputations(), expected);

	g_spSource->Compute('*', 10, -20);
	expected.push_back(-200);
	ASSERT_EQ(client.GetAllComputations(), expected);

	g_spSource->Compute('*', -10, -20);
	expected.push_back(200);
	ASSERT_EQ(client.GetAllComputations(), expected);

	g_spSource->Compute('*', 10, -10);
	expected.push_back(-100);
	ASSERT_EQ(client.GetAllComputations(), expected);
}

TEST(calculator_methods_test, divide)
{
	CCalculatorClient client(g_spSource);
	g_spSource->Compute('/', 4, 19);
	std::vector<int> expected = { 0 };
	ASSERT_EQ(client.GetAllComputations(), expected);

	g_spSource->Compute('/', 400, -20);
	expected.push_back(-20);
	ASSERT_EQ(client.GetAllComputations(), expected);

	g_spSource->Compute('/', -100, -20);
	expected.push_back(5);
	ASSERT_EQ(client.GetAllComputations(), expected);

	g_spSource->Compute('/', 10, -10);
	expected.push_back(-1);
	ASSERT_EQ(client.GetAllComputations(), expected);
}

TEST(multiple_subscribers_test, one_operation)
{
	CCalculatorClient client_1(g_spSource);
	CCalculatorClient client_2(g_spSource);
	CCalculatorClient client_3(g_spSource);
	g_spSource->Compute('+', 20, 19);
	std::vector<int> expected = { 39 };
	ASSERT_EQ(client_1.GetAllComputations(), expected);
	ASSERT_EQ(client_2.GetAllComputations(), expected);
	ASSERT_EQ(client_3.GetAllComputations(), expected);
}

TEST(multiple_subscribers_test, multiple_operations)
{
	CCalculatorClient client_1(g_spSource);
	CCalculatorClient client_2(g_spSource);
	CCalculatorClient client_3(g_spSource);
	g_spSource->Compute('+', 20, 19);
	g_spSource->Compute('-', 20, 19);
	g_spSource->Compute('*', 20, 19);
	g_spSource->Compute('/', 20, 19);
	std::vector<int> expected = { 39 , 1, 380, 1 };
	ASSERT_EQ(client_1.GetAllComputations(), expected);
	ASSERT_EQ(client_2.GetAllComputations(), expected);
	ASSERT_EQ(client_3.GetAllComputations(), expected);
}

int main(int argc, char** argv)
{
	CoInitialize(nullptr);
	auto hr = g_spSource.CoCreateInstance(__uuidof(Calculator));
	if (SUCCEEDED(hr))
	{
		testing::InitGoogleTest(&argc, argv);
		RUN_ALL_TESTS();
	}
	g_spSource = nullptr;
	CoUninitialize();
	return 0;	
}