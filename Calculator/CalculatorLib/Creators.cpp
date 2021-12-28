#include "pch.h"
#include "Creators.h"

std::shared_ptr<IAction> IActionCreator::getAction() {
	return action;
}