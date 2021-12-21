#include "pch.h"

#include "../CalculatorLib/CalculatorLib.h"

int culc (IAction& actor, int a, int b)
{
	return actor.calculate(a, b);
}

TEST(CalculatorTest, AddTest) {
	Add cl;
	EXPECT_EQ(culc(cl ,-5, 10), 5);
}

TEST(CalculatorTest, SubTest) {
	Sub cl;
	EXPECT_EQ(culc(cl, -5, 10), -15);
}

TEST(CalculatorTest, DivTest) {
	Div cl;
	EXPECT_EQ(culc(cl, -5, 10), 0);
}

TEST(CalculatorTest, MulTest) {
	Mul cl;
	EXPECT_EQ(culc(cl, -5, 10), -50);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}