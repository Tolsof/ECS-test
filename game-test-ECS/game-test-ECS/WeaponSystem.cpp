#include "stdafx.h"
#include <iostream>

#include "WeaponSystem.h"

void EffectSystem::apply_poison(Entity& target, Component* c) {
	Poison_t* poison = static_cast<Poison_t*>(c);

	// Logic affecting poison effect etc...
	target.addComponent(POISON, poison);
}
void EffectSystem::apply_physDamage(Entity& target, Component* c) {
	PhysDamage_t* damage_t = static_cast<PhysDamage_t*>(c);

	// Logic affecting damage etc...
	health_s.subHealth(target, damage_t->mod);
	std::cout << "The target took: " << damage_t->mod << " damage!" << '\n';
}
void EffectSystem::applyEffect(Entity& target, ComponentIndex i, Component* c) {
	// Sort effect by index
	switch (i) {

	case POISON: apply_poison(target, c);
		break;
	case PHYS_DAMAGE: apply_physDamage(target, c);
		break;
	}
}

void WeaponSystem::attack(Entity& attacker, Entity& target) {
	Weapon_t* e_weapon_t = static_cast<Weapon_t*>(attacker.getComponent(WEAPON));

	for (WeaponEffect effects : e_weapon_t->effects)
		effect_s.applyEffect(target, effects.index, effects.effect);
}