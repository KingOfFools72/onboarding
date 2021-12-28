#include "pch.h"
#include "Interfaces.h"

std::string Logger::log()
{
	std::string resStr = "Current action: " + name + ", result: " + std::to_string(calcRes);
	write(resStr);
	return resStr;
}