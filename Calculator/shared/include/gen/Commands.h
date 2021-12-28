#pragma once

#include "Creators.h"

class ICommand
{
public:
	virtual void execute() = 0;
	virtual ~ICommand() {};
};

class CalculatorCommand : public ICommand
{
public:
	CalculatorCommand(std::unique_ptr<IActionCreator> action)
		: creator(std::move(action)) {};

	CalculatorCommand(const CalculatorCommand& other) = delete;
	CalculatorCommand& operator=(const CalculatorCommand& other) = delete;

	CalculatorCommand(CalculatorCommand&& other) = default;
	CalculatorCommand& operator=(CalculatorCommand&& other) = default;

	void execute() override;
	const std::string& GetLogMessage() const;
	const int GetResultNumber() const;

private:
	std::unique_ptr<IActionCreator> creator;
	std::string message;
	int result = 0;
};