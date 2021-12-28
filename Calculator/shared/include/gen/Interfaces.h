#pragma once

#include <memory>
#include <string>

class Logger
{
public:
	std::string log();
	Logger(std::string name) : name(name), calcRes(0) {};
	virtual ~Logger() {};

protected:
	virtual void write(std::string&) = 0;
	const std::string name;
	int calcRes;
};