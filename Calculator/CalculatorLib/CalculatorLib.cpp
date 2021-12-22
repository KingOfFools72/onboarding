// CalculatorLib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "CalculatorLib.h"

void Invoker::addCommand(ICommand& command) {
	que.push(&command);
}

void Invoker::executeCommand(int a, int b)
{
	if (!que.empty())
	{
		que.front()->execute(a, b);
		que.pop();
	}
}