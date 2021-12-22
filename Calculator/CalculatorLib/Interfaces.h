#pragma once

#include <memory>
#include <string>

class Logger
{
public:
	void log();
	Logger(std::string name) : name(name), calcRes(0) {};
	virtual ~Logger() {};

protected:
	virtual void write(std::string&) = 0;
	const std::string name;
	int calcRes;
};

class IAction
{
public:
	virtual int calculate(int, int) = 0;
	virtual ~IAction() {};
};

class IActionCreator
{
public:
	virtual std::shared_ptr<IAction> getAction() = 0;
	virtual ~IActionCreator() {};

protected:
	std::shared_ptr<IAction> action;
};

class ICommand
{
public:
	virtual void execute(int, int) = 0;
	virtual ~ICommand() {};

protected:
	std::unique_ptr<IActionCreator> creator;
};