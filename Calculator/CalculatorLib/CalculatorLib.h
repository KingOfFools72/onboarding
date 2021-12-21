#pragma once

#include <memory>
#include <queue>

class IAction
{
public:
	virtual int calculate(int, int) = 0;
	virtual ~IAction() {};
};

class NullAction : public IAction
{
	int calculate(int, int) override;
};

class Add : public IAction
{
public:
	int calculate(int, int) override;
};

class Sub : public IAction
{
public:
	int calculate(int, int) override;
};

class Div : public IAction
{
public:
	int calculate(int, int) override;
};

class Mul : public IAction
{
public:
	int calculate(int, int) override;
};

class IActionCreator 
{
public:
	virtual std::shared_ptr<IAction> getAction() = 0;
	virtual ~IActionCreator() {};

protected:
	std::shared_ptr<IAction> action;
};

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

class ICommand
{
public:
	virtual void execute(int, int) = 0;
	virtual ~ICommand() {};

protected:
	std::unique_ptr<IActionCreator> creator;
};

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

class Invoker
{
public:
	void addCommand(std::unique_ptr<ICommand>);
	void executeCommand(int a, int b);

private:
	std::queue<std::unique_ptr<ICommand>> que;
};