#pragma once
#include <vector>

enum ComponentIndex {
	POISON = 0,
	PHYS_DAMAGE,
	HEALTH,
	WEAPON,
	COORD,
	INDEXMAX
};

struct Component {};

struct Poison_t : public Component {
	int duration;
	int mod;

	Poison_t(int d = 5, int m = 1) : duration(d), mod(m) {}
};

struct BigPoison_t : public Poison_t {
	BigPoison_t(int d = 7, int m = 2) : Poison_t(d, m) {}
};

struct PhysDamage_t : public Component {
	int mod;

public:
	PhysDamage_t(int m = 3) : mod(m) {}
};

struct Health_t : public Component {
	int maxHp;
	int curHp;
	bool is_dead;

	Health_t(int max) {
		maxHp = max;
		curHp = max;
		is_dead = false;
	}
};

struct WeaponEffect {
	ComponentIndex index;
	Component* effect;

	WeaponEffect(ComponentIndex i, Component* e) : index(i), effect(e) {}
};

struct Weapon_t : public Component {
	std::vector<WeaponEffect> effects;
};

struct Coord_t : public Component {
	int loc_x;
	int loc_y;

	Coord_t(int x, int y) : loc_x(x), loc_y(y) {}
};