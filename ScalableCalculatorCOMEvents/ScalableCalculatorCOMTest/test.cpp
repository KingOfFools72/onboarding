#include "pch.h"

#include "CCalculatorClient.h"

CComModule _Module;
extern __declspec(selectany) CAtlModule* _pAtlModule = &_Module;

CComPtr<ICalculator> g_spSource;

TEST(calculator_methods_test, add)
{
	CCalculatorClient client(g_spSource);
	client.Subscribe();
	LONGLONG res = 0;
	g_spSource->Compute('+', 4, 19, &res);
	ASSERT_EQ(res, 23);

	g_spSource->Compute('+', 10, -20, &res);
	ASSERT_EQ(res, -10);

	g_spSource->Compute('+', -10, -20, &res);
	ASSERT_EQ(res, -30);

	g_spSource->Compute('+', 10, -10, &res);
	ASSERT_EQ(res, 0);
}

TEST(calculator_methods_test, subtract)
{
	CCalculatorClient client(g_spSource);
	client.Subscribe();
	LONGLONG res = 0;
	g_spSource->Compute('-', 4, 19, &res);
	ASSERT_EQ(res, -15);

	g_spSource->Compute('-', 10, -20, &res);
	ASSERT_EQ(res, 30);

	g_spSource->Compute('-', -10, -20, &res);
	ASSERT_EQ(res, 10);

	g_spSource->Compute('-', 10, -10, &res);
	ASSERT_EQ(res, 20);
}

TEST(calculator_methods_test, multiply)
{
	CCalculatorClient client(g_spSource);
	client.Subscribe();
	LONGLONG res = 0;
	g_spSource->Compute('*', 4, 19, &res);
	ASSERT_EQ(res, 76);

	g_spSource->Compute('*', 10, -20, &res);
	ASSERT_EQ(res, -200);

	g_spSource->Compute('*', -10, -20, &res);
	ASSERT_EQ(res, 200);

	g_spSource->Compute('*', 10, -10, &res);
	ASSERT_EQ(res, -100);
}

TEST(calculator_methods_test, divide)
{
	CCalculatorClient client(g_spSource);
	client.Subscribe();
	LONGLONG res = 0;
	g_spSource->Compute('/', 4, 19, &res);
	ASSERT_EQ(res, 0);

	g_spSource->Compute('/', 400, -20, &res);
	ASSERT_EQ(res, -20);

	g_spSource->Compute('/', -100, -20, &res);
	ASSERT_EQ(res, 5);

	g_spSource->Compute('/', 10, -10, &res);
	ASSERT_EQ(res, -1);
}

TEST(multiple_subscribers_test, one_operation)
{
	CCalculatorClient client_1(g_spSource);
	CCalculatorClient client_2(g_spSource);
	CCalculatorClient client_3(g_spSource);
	client_1.Subscribe();
	client_2.Subscribe();
	client_3.Subscribe();
	LONGLONG res = 0;
	g_spSource->Compute('+', 20, 19, &res);
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
	client_1.Subscribe();
	client_2.Subscribe();
	client_3.Subscribe();
	LONGLONG res = 0;
	g_spSource->Compute('+', 20, 19, &res);
	g_spSource->Compute('-', 20, 19, &res);
	g_spSource->Compute('*', 20, 19, &res);
	g_spSource->Compute('/', 20, 19, &res);
	std::vector<int> expected = { 39 , 1, 380, 1 };
	ASSERT_EQ(client_1.GetAllComputations(), expected);
	ASSERT_EQ(client_2.GetAllComputations(), expected);
	ASSERT_EQ(client_3.GetAllComputations(), expected);
}

int main(int argc, char** argv)
{
	CoInitialize(NULL);
	auto hr = g_spSource.CoCreateInstance(__uuidof(Calculator));
	if (!SUCCEEDED(hr))
	{
		return -1;
	}
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}