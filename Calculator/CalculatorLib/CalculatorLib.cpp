// CalculatorLib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "CalculatorLib.h"

int NullAction::calculate(int a, int b) {
	return INT_MAX;
}

int Add::calculate(int a, int b) {
	return a + b;
}

int Sub::calculate(int a, int b) {
	return a - b;
}

int Div::calculate(int a, int b) {
	return a / b;
}

int Mul::calculate(int a, int b) {
	return a * b;
}

std::shared_ptr<IAction> AddCreator::getAction() {
	return action;
}

std::shared_ptr<IAction> SubCreator::getAction() {
	return action;
}

std::shared_ptr<IAction> DivCreator::getAction() {
	return action;
}

std::shared_ptr<IAction> MulCreator::getAction() {
	return action;
}

void AddCommand::execute(int a, int b) {
	creator->getAction()->calculate(a, b);
}

void SubCommand::execute(int a, int b) {
	creator->getAction()->calculate(a, b);
}

void DivCommand::execute(int a, int b) {
	creator->getAction()->calculate(a, b);
}

void MulCommand::execute(int a, int b) {
	creator->getAction()->calculate(a, b);
}

void Invoker::addCommand(std::unique_ptr<ICommand> command) {
	que.push(std::move(command));
}

void Invoker::executeCommand(int a, int b)
{
	if (!que.empty())
	{
		que.front()->execute(a, b);
		que.pop();
	}
}