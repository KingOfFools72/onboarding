#include "pch.h"
#include "Commands.h"

void CalculatorCommand::execute()
{
	result = creator->getAction()->calculate();
	message = creator->getAction()->log();
};

const std::string& CalculatorCommand::GetLogMessage() const
{
	return message;
};

const int CalculatorCommand::GetResultNumber() const
{
	return result;
}