#include "stdafx.h"
#include "Entity.h"
#include <iostream>

void Entity::addComponent(ComponentIndex i, Component* c) {
	components[i] = c;
}
void Entity::deleteComponent(ComponentIndex i) {
	delete components[i];
	components[i] = nullptr;
}
Component* Entity::getComponent(ComponentIndex i) {
	return components[i];
}
bool Entity::compExists(ComponentIndex i) {
	if (components[i] == nullptr) {
		return false;
	}
	else {
		return true;
	}
}
int Entity::getGUID() {
	return guid;
}