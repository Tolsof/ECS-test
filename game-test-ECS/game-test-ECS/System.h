#pragma once
#include "Entity.h"
#include <iostream>

class System {};

class HealthSystem : public System {
public:
	void subHealth(Entity& e, int amount);
	bool checkDead(Entity& e);
};

class PoisonSystem : public System {
	// HealthSystem is used instead
	// of directly accessing health component
	HealthSystem health_s;
public:
	void update(Entity& e);
};

class CoordSystem : public System {
public:
	int getX(Entity& e) const;
	int getY(Entity& e) const;
	void setX(Entity& e, int new_x);
	void setY(Entity& e, int new_y);
	void setX_Y(Entity& e, int new_x, int new_y);
};