// CalculatorLib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "CalculatorLib.h"

#include <iostream>

void Calculator::AddCommand(CalculatorCommand command)
{
	commands.push(std::move(command));
	++index;
	sig.connect(std::bind(&CalculatorCommand::execute, std::ref(commands.back())));
};

void Calculator::Compute()
{
	sig();

	while (!commands.empty())
	{
		resultMessages.push_back(commands.front().GetLogMessage());
		resultNumbers.push_back(commands.front().GetResultNumber());
		commands.pop();
	}
};

void Calculator::PrintResultMessages() const
{
	for (const auto& str : resultMessages)
	{
		std::cout << str << '\n';
	}
};

void Calculator::PrintResultNumbers() const
{
	for (const auto& number : resultNumbers)
	{
		std::cout << number << '\n';
	}
};

const std::vector<std::string>& Calculator::GetResultMessages() const
{
	return resultMessages;
};

const std::vector<int>& Calculator::GetResultNumbers() const
{
	return resultNumbers;
};