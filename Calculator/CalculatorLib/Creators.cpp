#include "pch.h"
#include "Creators.h"

std::shared_ptr<IAction> AddCreator::getAction() {
	return action;
}

std::shared_ptr<IAction> SubCreator::getAction() {
	return action;
}

std::shared_ptr<IAction> DivCreator::getAction() {
	return action;
}

std::shared_ptr<IAction> MulCreator::getAction() {
	return action;
}