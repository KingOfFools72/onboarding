#include "gtest/gtest.h"

#include <CalculatorLib.h>

#include <typeinfo>

#include <boost/signals2.hpp>

TEST(calculatorLogicTests, test)
{
	Calculator calculator;
	calculator.Compute();
	std::vector<std::string> expected;
	ASSERT_EQ(expected, calculator.GetResultMessages());
};

TEST(calculatorLogTest, add)
{
	Calculator calculator;

	calculator.AddCommand(CalculatorCommand(std::make_unique<AddCreator>(6, 4)));
	calculator.AddCommand(CalculatorCommand(std::make_unique<AddCreator>(-127, -1)));
	calculator.AddCommand(CalculatorCommand(std::make_unique<AddCreator>(6, -6)));
	calculator.AddCommand(CalculatorCommand(std::make_unique<AddCreator>(-40, 4)));

	calculator.Compute();

	std::vector<std::string> expected =
	{
		"Current action: Add, result: 10",
		"Current action: Add, result: -128",
		"Current action: Add, result: 0",
		"Current action: Add, result: -36"
	};
	ASSERT_EQ(expected, calculator.GetResultMessages());
};

TEST(calculatorLogTest, sub)
{
	Calculator calculator;

	calculator.AddCommand(CalculatorCommand(std::make_unique<SubCreator>(6, 4)));
	calculator.AddCommand(CalculatorCommand(std::make_unique<SubCreator>(-127, 1)));
	calculator.AddCommand(CalculatorCommand(std::make_unique<SubCreator>(6, -6)));
	calculator.AddCommand(CalculatorCommand(std::make_unique<SubCreator>(-10, -20)));

	calculator.Compute();

	std::vector<std::string> expected =
	{
		"Current action: Sub, result: 2",
		"Current action: Sub, result: -128",
		"Current action: Sub, result: 12",
		"Current action: Sub, result: 10"
	};
	ASSERT_EQ(expected, calculator.GetResultMessages());
};

TEST(calculatorLogTest, mul)
{
	Calculator calculator;

	calculator.AddCommand(CalculatorCommand(std::make_unique<MulCreator>(6, 4)));
	calculator.AddCommand(CalculatorCommand(std::make_unique<MulCreator>(-127, 1)));
	calculator.AddCommand(CalculatorCommand(std::make_unique<MulCreator>(6, -6)));
	calculator.AddCommand(CalculatorCommand(std::make_unique<MulCreator>(-10, -20)));

	calculator.Compute();

	std::vector<std::string> expected =
	{
		"Current action: Mul, result: 24",
		"Current action: Mul, result: -127",
		"Current action: Mul, result: -36",
		"Current action: Mul, result: 200"
	};
	ASSERT_EQ(expected, calculator.GetResultMessages());
};

TEST(calculatorLogTest, div)
{
	Calculator calculator;

	calculator.AddCommand(CalculatorCommand(std::make_unique<DivCreator>(6, 4)));
	calculator.AddCommand(CalculatorCommand(std::make_unique<DivCreator>(-127, 1)));
	calculator.AddCommand(CalculatorCommand(std::make_unique<DivCreator>(6, -6)));
	calculator.AddCommand(CalculatorCommand(std::make_unique<DivCreator>(-20, -10)));

	calculator.Compute();

	std::vector<std::string> expected =
	{
		"Current action: Div, result: 1",
		"Current action: Div, result: -127",
		"Current action: Div, result: -1",
		"Current action: Div, result: 2"
	};
	ASSERT_EQ(expected, calculator.GetResultMessages());

	//! Divide on zero
	calculator.AddCommand(CalculatorCommand(std::make_unique<DivCreator>(-20, 0)));
	EXPECT_ANY_THROW(calculator.Compute());
};

TEST(calculatorLogTest, null)
{
	Calculator calculator;

	calculator.AddCommand(CalculatorCommand(std::make_unique<NullCreator>(0, 0)));

	calculator.Compute();

	std::vector<std::string> expected =
	{ "Current action: Null, result: " + std::to_string(INT_MAX) + "" };
	ASSERT_EQ(expected, calculator.GetResultMessages());
};

TEST(calculatorResTest, add)
{
	Calculator calculator;


	calculator.AddCommand(CalculatorCommand(std::make_unique<AddCreator>(6, 4)));
	calculator.AddCommand(CalculatorCommand(std::make_unique<AddCreator>(-127, -1)));
	calculator.AddCommand(CalculatorCommand(std::make_unique<AddCreator>(6, -6)));
	calculator.AddCommand(CalculatorCommand(std::make_unique<AddCreator>(-40, 4)));

	calculator.Compute();

	std::vector<int> expected = { 10, -128, 0, -36 };

	ASSERT_EQ(expected, calculator.GetResultNumbers());
};

TEST(calculatorResTest, sub)
{
	Calculator calculator;

	calculator.AddCommand(CalculatorCommand(std::make_unique<SubCreator>(6, 4)));
	calculator.AddCommand(CalculatorCommand(std::make_unique<SubCreator>(-127, -1)));
	calculator.AddCommand(CalculatorCommand(std::make_unique<SubCreator>(6, -6)));
	calculator.AddCommand(CalculatorCommand(std::make_unique<SubCreator>(-40, 4)));

	calculator.Compute();

	std::vector<int> expected = { 2, -126, 12, -44 };

	ASSERT_EQ(expected, calculator.GetResultNumbers());
};

TEST(calculatorResTest, mul)
{
	Calculator calculator;

	calculator.AddCommand(CalculatorCommand(std::make_unique<MulCreator>(6, 4)));
	calculator.AddCommand(CalculatorCommand(std::make_unique<MulCreator>(-127, -1)));
	calculator.AddCommand(CalculatorCommand(std::make_unique<MulCreator>(6, -6)));
	calculator.AddCommand(CalculatorCommand(std::make_unique<MulCreator>(-40, 4)));

	calculator.Compute();

	std::vector<int> expected = { 24, 127, -36, -160 };

	ASSERT_EQ(expected, calculator.GetResultNumbers());
};

TEST(calculatorResTest, div)
{
	Calculator calculator;

	calculator.AddCommand(CalculatorCommand(std::make_unique<DivCreator>(6, 4)));
	calculator.AddCommand(CalculatorCommand(std::make_unique<DivCreator>(-127, -1)));
	calculator.AddCommand(CalculatorCommand(std::make_unique<DivCreator>(6, -6)));
	calculator.AddCommand(CalculatorCommand(std::make_unique<DivCreator>(-40, 4)));

	calculator.Compute();

	std::vector<int> expected = { 1, 127, -1, -10 };

	ASSERT_EQ(expected, calculator.GetResultNumbers());
};

TEST(calculatorResTest, null)
{
	Calculator calculator;

	calculator.AddCommand(CalculatorCommand(std::make_unique<NullCreator>(0, 0)));

	calculator.Compute();

	std::vector<int> expected = { INT_MAX };

	ASSERT_EQ(expected, calculator.GetResultNumbers());
};

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}