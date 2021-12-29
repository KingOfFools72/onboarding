#pragma once

#include "Interfaces.h"
namespace NativeCalculator
{
class IAction: public Logger
{
public:
	IAction(std::string name, int lhs, int rhs) : Logger(name) , lhs_(lhs), rhs_(rhs) {};
	virtual int calculate() = 0;
	virtual ~IAction() {};

protected:
	int lhs_, rhs_;
};

class NullAction : public IAction
{
public:
	NullAction(int lhs, int rhs) : IAction("Null", lhs, rhs) {};
	int calculate() override;

private:
	void write(std::string&) override;
};

class Add : public IAction
{
public:
	Add(int lhs, int rhs) : IAction("Add", lhs, rhs) {};
	int calculate() override;

private:
	void write(std::string&) override;
};

class Sub : public IAction
{
public:
	Sub(int lhs, int rhs) : IAction("Sub", lhs, rhs) {};
	int calculate() override;

private:
	void write(std::string&) override;
};

class Div : public IAction
{
public:
	Div(int lhs, int rhs) : IAction("Div", lhs, rhs) {};
	int calculate() override;

private:
	void write(std::string&) override;
};

class Mul : public IAction
{
public:
	Mul(int lhs, int rhs) : IAction("Mul", lhs, rhs) {};
	int calculate() override;

private:
	void write(std::string&) override;
};
}