#include "stdafx.h"
#include <iostream>

#include "System.h"
#include "Component.h"

// START HEALTH SYSTEM
void HealthSystem::subHealth(Entity& e, int amount) {
	if (e.compExists(HEALTH)) {
		Health_t* health_t = static_cast<Health_t*>(e.getComponent(HEALTH));

		health_t->curHp -= amount;
		std::cout << health_t->curHp << '\n';

		if (health_t->curHp <= 0) {
			health_t->is_dead = true;
		}
	}
	else {
		std::cout << "Health component doesn't exist." << '\n';
	}
}
bool HealthSystem::checkDead(Entity& e) {
	Health_t* e_health_t = static_cast<Health_t*>(e.getComponent(HEALTH));
	if (e_health_t->is_dead) {
		return true;
	}
	else {
		return false;
	}
}

// START POISON SYSTEM
void PoisonSystem::update(Entity& e) {
	if (e.compExists(POISON)) {
		Poison_t* e_poison_t = static_cast<Poison_t*>(e.getComponent(POISON));
		
		int amount = e_poison_t->mod;
		health_s.subHealth(e, amount);
		
		e_poison_t->duration -= 1;

		if (e_poison_t->duration <= 0) {
			e.deleteComponent(POISON);
		}
	}
	else {
		std::cout << "Poison does not exist on this entity." << '\n';
	}
}

// START COORD SYSTEM
int CoordSystem::getX(Entity& e) const {
	Coord_t* e_coord_t = static_cast<Coord_t*>(e.getComponent(COORD));
	return e_coord_t->loc_x;
}
int CoordSystem::getY(Entity& e) const {
	Coord_t* e_coord_t = static_cast<Coord_t*>(e.getComponent(COORD));
	return e_coord_t->loc_y;
}
void CoordSystem::setX(Entity& e, int new_x) {
	Coord_t* e_coord_t = static_cast<Coord_t*>(e.getComponent(COORD));
	e_coord_t->loc_x = new_x;
}
void CoordSystem::setY(Entity& e, int new_y) {
	Coord_t* e_coord_t = static_cast<Coord_t*>(e.getComponent(COORD));
	e_coord_t->loc_y = new_y;
}
void CoordSystem::setX_Y(Entity& e, int new_x, int new_y) {
	Coord_t* e_coord_t = static_cast<Coord_t*>(e.getComponent(COORD));
	e_coord_t->loc_x = new_x;
	e_coord_t->loc_y = new_y;
}