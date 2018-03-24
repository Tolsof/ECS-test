#pragma once
#include "Component.h"
#include <memory>

class Entity {
	int guid;
	// nullptr is used to check if exists
	Component* components[INDEXMAX] = {nullptr};

public:
	void addComponent(ComponentIndex i, Component* c);
	void deleteComponent(ComponentIndex i);
	Component* getComponent(ComponentIndex i);
	bool compExists(ComponentIndex i);
	int getGUID();

	Entity(int id) : guid(id) {}
};