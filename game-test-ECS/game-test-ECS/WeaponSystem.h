#pragma once

#include "System.h"
#include "Component.h"

class Entity;

class EffectSystem : public System {
	HealthSystem health_s;

public:
	void apply_poison(Entity& target, Component* c);
	void apply_physDamage(Entity& target, Component* c);
	void applyEffect(Entity& target, ComponentIndex i, Component* c);
};

class WeaponSystem : public System {
	EffectSystem effect_s;
public:
	void attack(Entity& e, Entity& t);
};