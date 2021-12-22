#pragma once

#include <queue>
#include "Interfaces.h"

class Invoker
{
public:
	void addCommand(ICommand&);
	void executeCommand(int a, int b);

private:
	std::queue<ICommand*> que;
};