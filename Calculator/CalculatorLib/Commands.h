#pragma once

#include "Creators.h"

class AddCommand : public ICommand
{
public:
	AddCommand() { creator = std::make_unique<AddCreator>(); };
	void execute(int a, int b) override;
};

class SubCommand : public ICommand
{
public:
	SubCommand() { creator = std::make_unique<SubCreator>(); };
	void execute(int a, int b) override;
};

class DivCommand : public ICommand
{
public:
	DivCommand() { creator = std::make_unique<DivCreator>(); };
	void execute(int a, int b) override;
};

class MulCommand : public ICommand
{
public:
	MulCommand() { creator = std::make_unique<MulCreator>(); };
	void execute(int a, int b) override;
};