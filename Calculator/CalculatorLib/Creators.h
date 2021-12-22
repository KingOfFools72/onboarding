#pragma once

#include "Actions.h"

class AddCreator : public IActionCreator
{
public:
	AddCreator() { action = std::make_shared<Add>(); };
	std::shared_ptr<IAction> getAction() override;
};

class SubCreator : public IActionCreator
{
public:
	SubCreator() { action = std::make_shared<Sub>(); };
	std::shared_ptr<IAction> getAction() override;
};

class DivCreator : public IActionCreator
{
public:
	DivCreator() { action = std::make_shared<Div>(); };
	std::shared_ptr<IAction> getAction() override;
};

class MulCreator : public IActionCreator
{
public:
	MulCreator() { action = std::make_shared<Mul>(); };
	std::shared_ptr<IAction> getAction() override;
};