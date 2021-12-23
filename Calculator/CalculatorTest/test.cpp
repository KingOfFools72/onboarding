#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../CalculatorLib/CalculatorLib.h"
#include "../CalculatorLib/Commands.h"
#include "../CalculatorLib/Async.h"

#include <typeinfo>

#include <boost/signals2.hpp>
#include <boost/optional/optional_io.hpp>
#include <boost/shared_ptr.hpp>

class MockAddCommand : public ICommand
{
public:
	MOCK_METHOD(void, execute, (int a, int b), (override));
};

class MockSubCommand : public ICommand
{
public:
	MOCK_METHOD(void, execute, (int a, int b), (override));
};

TEST(ActionsTest, IActionTest) {
	std::unique_ptr<IAction> action = std::make_unique<Add>();
	EXPECT_EQ(action->calculate(-5, 10), 5);
	testing::internal::CaptureStdout();	
	std::string output = testing::internal::GetCapturedStdout();

	action = std::make_unique<Sub>();
	EXPECT_EQ(action->calculate(-5, 10), -15);

	action = std::make_unique<Div>();
	EXPECT_EQ(action->calculate(-5, 10), 0);

	action = std::make_unique<Mul>();
	EXPECT_EQ(action->calculate(-5, 10), -50);

	action = std::make_unique<NullAction>();
	EXPECT_EQ(action->calculate(-5, 10), INT_MAX);
}

TEST(ActionsTest, LoggerTest) {
	Add ad;
	ad.calculate(5, 5);
	testing::internal::CaptureStdout();
	ad.log();	
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(output, "Current action: Add, result: 10\n");
}

TEST(CreatorsTest, Test) {
	std::unique_ptr<IActionCreator> creator = std::make_unique<AddCreator>();
	EXPECT_EQ(typeid(*creator->getAction()), typeid(Add));

	creator = std::make_unique<SubCreator>();
	EXPECT_EQ(typeid(*creator->getAction()), typeid(Sub));

	creator = std::make_unique<DivCreator>();
	EXPECT_EQ(typeid(*creator->getAction()), typeid(Div));

	creator = std::make_unique<MulCreator>();
	EXPECT_EQ(typeid(*creator->getAction()), typeid(Mul));
}

TEST(InvokerTest, Test) {

	MockAddCommand mac;
	MockSubCommand msc;

	EXPECT_CALL(mac, execute(2, 4)).Times(1);
	EXPECT_CALL(msc, execute(2, 4)).Times(1);

	Invoker inv;
	inv.addCommand(mac);
	inv.addCommand(msc);
	inv.executeCommand(2, 4);
	inv.executeCommand(2, 4);
	inv.executeCommand(2, 4);
}

TEST(AsyncTest, Test) {

	//boost::signals2::signal<int(int, int)> sig,
	//	aggregate_values<std::vector<std::pair<int,int>>>>;
	//
	//Add ad;

	//sig.connect(&Add::calculate);
	//std::queue<IAction> que;
	//que.push(Add());
	//que.front().calculate(3, 4);


	//
	//std::cout << sig.num_slots() << std::endl;
	//sig(1,2);
    /*sig.connect(&Add::calculate);
	sig.connect(&Sub::calculate);
	sig.connect(&Mul::calculate);*/
	//sig(2,5);
	//std::vector<std::pair<int, int>> res = sig(2, 5);

	//EXPECT_EQ(res[0].first, 0);
	//EXPECT_EQ(res[1].first, 1);
	//EXPECT_EQ(res[2].first, 2);

	//EXPECT_EQ(res[0].second, 2 + 5);
	//EXPECT_EQ(res[1].second, 2 - 5);
	//EXPECT_EQ(res[2].second, 2 * 5);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}