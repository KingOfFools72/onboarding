#pragma once

#include "Interfaces.h"

class NullAction : public IAction, public Logger
{
public:
	NullAction() : Logger("Null") {};
	int calculate(int, int) override;

private:
	void write(std::string&) override;
};

class Add : public IAction, public Logger
{
public:
	Add() : Logger("Add") {};
	int calculate(int, int) override;

private:
	void write(std::string&) override;
};

class Sub : public IAction, public Logger
{
public:
	Sub() : Logger("Sub") {};
	int calculate(int, int) override;

private:
	void write(std::string&) override;
};

class Div : public IAction, public Logger
{
public:
	Div() : Logger("Div") {};
	int calculate(int, int) override;

private:
	void write(std::string&) override;
};

class Mul : public IAction, public Logger
{
public:
	Mul() : Logger("Mul") {};
	int calculate(int, int) override;

private:
	void write(std::string&) override;
};