#pragma once

#include "Actions.h"
namespace NativeCalculator
{
class IActionCreator
{
public:
	IActionCreator(int lhs, int rhs) {};
	virtual std::shared_ptr<IAction> getAction();
	virtual ~IActionCreator() {};

protected:
	std::shared_ptr<IAction> action;
};

class AddCreator : public IActionCreator
{
public:
	AddCreator(int lhs, int rhs) : IActionCreator(lhs, rhs) { action = std::make_shared<Add>(lhs, rhs); };
};

class SubCreator : public IActionCreator
{
public:
	SubCreator(int lhs, int rhs) : IActionCreator(lhs, rhs) { action = std::make_shared<Sub>(lhs, rhs); };
};

class DivCreator : public IActionCreator
{
public:
	DivCreator(int lhs, int rhs) : IActionCreator(lhs, rhs) { action = std::make_shared<Div>(lhs, rhs); };
};

class MulCreator : public IActionCreator
{
public:
	MulCreator(int lhs, int rhs) : IActionCreator(lhs, rhs) { action = std::make_shared<Mul>(lhs, rhs); };
};

class NullCreator : public IActionCreator
{
public:
	NullCreator(int lhs, int rhs) : IActionCreator(lhs, rhs) { action = std::make_shared<NullAction>(lhs, rhs); };
};
}