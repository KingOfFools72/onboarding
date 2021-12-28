#include "pch.h"

#include <iostream>
#include <atlbase.h>

#import "../CalculaorOutCOM/Debug/CalculaorOutCOM.tlb" named_guids raw_interfaces_only
#import "../CalculatorCOM/Debug/CalculatorCOM.tlb" named_guids raw_interfaces_only

using namespace ATL;
using namespace CalculaorOutCOMLib;
using namespace CalculatorCOMLib;

CComQIPtr<IOutCalculator> OutCalc;
CComQIPtr<IInCOMCalculator> InCalc;
UINT* res = new UINT;

TEST(outCalcMethodsTests, add)
{	
	OutCalc->Add(10, 20, res);
	ASSERT_EQ(*res, 30);
	OutCalc->Add(10, -20, res);
	ASSERT_EQ(*res, -10);
	OutCalc->Add(-10, -20, res);
	ASSERT_EQ(*res, -30);
	OutCalc->Add(10, -10, res);
	ASSERT_EQ(*res, 0);
}

TEST(outCalcMethodsTests, sub)
{
	OutCalc->Sub(10, 20, res);
	ASSERT_EQ(*res, -10);
	OutCalc->Sub(10, -20, res);
	ASSERT_EQ(*res, 30);
	OutCalc->Sub(-10, -20, res);
	ASSERT_EQ(*res, 10);
	OutCalc->Sub(10, -10, res);
	ASSERT_EQ(*res, 20);
}

TEST(outCalcMethodsTests, mul)
{
	OutCalc->Mul(10, 20, res);
	ASSERT_EQ(*res, 200);
	OutCalc->Mul(10, -20, res);
	ASSERT_EQ(*res, -200);
	OutCalc->Mul(-10, -20, res);
	ASSERT_EQ(*res, 200);
	OutCalc->Mul(10, -10, res);
	ASSERT_EQ(*res, -100);
}

TEST(outCalcMethodsTests, div)
{
	OutCalc->Div(10, 20, res);
	ASSERT_EQ(*res, 0);
	OutCalc->Div(200, -20, res);
	ASSERT_EQ(*res, -10);
	OutCalc->Div(-100000, -20, res);
	ASSERT_EQ(*res, 5000);
	OutCalc->Div(10, -10, res);
	ASSERT_EQ(*res, -1);

	ASSERT_EQ(OutCalc->Div(10, 0, res), E_FAIL);
}

/////////////////////////////////////

TEST(inCalcMethodsTests, add)
{
	InCalc->Add(10, 20, res);
	ASSERT_EQ(*res, 30);
	InCalc->Add(10, -20, res);
	ASSERT_EQ(*res, -10);
	InCalc->Add(-10, -20, res);
	ASSERT_EQ(*res, -30);
	InCalc->Add(10, -10, res);
	ASSERT_EQ(*res, 0);
}

TEST(inCalcMethodsTests, sub)
{
	InCalc->Sub(10, 20, res);
	ASSERT_EQ(*res, -10);
	InCalc->Sub(10, -20, res);
	ASSERT_EQ(*res, 30);
	InCalc->Sub(-10, -20, res);
	ASSERT_EQ(*res, 10);
	InCalc->Sub(10, -10, res);
	ASSERT_EQ(*res, 20);
}

TEST(inCalcMethodsTests, mul)
{
	InCalc->Mul(10, 20, res);
	ASSERT_EQ(*res, 200);
	InCalc->Mul(10, -20, res);
	ASSERT_EQ(*res, -200);
	InCalc->Mul(-10, -20, res);
	ASSERT_EQ(*res, 200);
	InCalc->Mul(10, -10, res);
	ASSERT_EQ(*res, -100);
}

TEST(inCalcMethodsTests, div)
{
	InCalc->Div(10, 20, res);
	ASSERT_EQ(*res, 0);
	InCalc->Div(200, -20, res);
	ASSERT_EQ(*res, -10);
	InCalc->Div(-100000, -20, res);
	ASSERT_EQ(*res, 5000);
	OutCalc->Div(10, -10, res);
	ASSERT_EQ(*res, -1);

	ASSERT_EQ(OutCalc->Div(10, 0, res), E_FAIL);
}


int main(int argc, char** argv)
{
	CoInitialize(0);
	auto hr = OutCalc.CoCreateInstance(__uuidof(OutCalculator));
	if (!SUCCEEDED(hr))
	{
		return -1;
	}
	hr = InCalc.CoCreateInstance(__uuidof(InCOMCalculator));
	if (!SUCCEEDED(hr))
	{
		return -1;
	}
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}