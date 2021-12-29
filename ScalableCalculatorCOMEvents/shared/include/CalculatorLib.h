#pragma once

#include <queue>
#include <vector>
#include <boost/signals2.hpp>

#include "Commands.h"
namespace NativeCalculator
{
class Calculator
{
	typedef boost::signals2::signal<void()>  signal_t;
public:
	void AddCommand(CalculatorCommand command);
	void Compute();

	void PrintResultMessages() const;
	void PrintResultNumbers() const;

	const std::vector<std::string>& GetResultMessages() const;
	const std::vector<int>& GetResultNumbers() const;

private:
	std::queue<CalculatorCommand> commands;
	std::vector<std::string> resultMessages;
	std::vector<int> resultNumbers;
	signal_t sig;
	int index = -1;
};
}