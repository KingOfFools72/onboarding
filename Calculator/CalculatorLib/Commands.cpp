#include "pch.h"
#include "Commands.h"

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