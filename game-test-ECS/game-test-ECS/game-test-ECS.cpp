// gaplayer-test-ECS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "System.h"
#include "WeaponSystem.h"
#include "EntityMap.h"


int main() {
	// Array that all entities will be held
	Entity* guid_map[10] = {nullptr};

	Entity player(1);
	player.addComponent(HEALTH, new Health_t(10));

	Entity goblin(5);
	goblin.addComponent(HEALTH, new Health_t(5));
	goblin.addComponent(COORD, new Coord_t(0, 0));

	// Creates weapon for goblin
	Weapon_t dagger;
	dagger.effects.emplace_back(PHYS_DAMAGE, new PhysDamage_t);
	dagger.effects.emplace_back(POISON, new Poison_t);
	// Adds weapon to goblin
	goblin.addComponent(WEAPON, new Weapon_t(dagger));

	// Adds goblin entity to array at goblin guid index
	guid_map[goblin.getGUID()] = new Entity(goblin);

	PoisonSystem poison_s;
	HealthSystem health_s;
	CoordSystem coord_s;
	WeaponSystem weapon_s;

	// Adds weapon effect to player entity
	std::cout << "Goblin attacking player!" << '\n';
	weapon_s.attack(*guid_map[goblin.getGUID()], player);

	// Adds poison component to entity at guid indexs
	guid_map[goblin.getGUID()]->addComponent(POISON, new Poison_t);
		
	//Updates poison on entities
	std::cout << "Updating poison on player" << '\n';
	std::cout << "Player current health: ";

	poison_s.update(player);

	while (!health_s.checkDead(*guid_map[goblin.getGUID()]))
	{
		std::cout << "Updating poison on goblin" << '\n';
		std::cout << "Goblin current health: ";
		poison_s.update(*guid_map[goblin.getGUID()]);
		std::cin.ignore();
	}
	
	EntityMap map(5, 5);

	map.setGUID(coord_s.getX(*guid_map[goblin.getGUID()]),
		        coord_s.getY(*guid_map[goblin.getGUID()]),
		        goblin.getGUID());

	std::cout << "guid for gobbo: " << map.getGUID(0, 0) << '\n';

	std::cout << guid_map[map.getGUID(0, 0)] << '\n';

	std::cin.ignore();
    return 0;
}