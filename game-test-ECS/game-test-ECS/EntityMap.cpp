#include "stdafx.h"
#include "EntityMap.h"

int EntityMap::getGUID(int x, int y) const {
	return entity_map[x][y];
}
void EntityMap::setGUID(int x, int y, int guid) {
	entity_map[x][y] = guid;
}
void EntityMap::clearLoc(int x, int y) {
	entity_map[x][y] = 0;
}
EntityMap::EntityMap(int x, int y) {
	std::vector<std::vector<int>> fill(x, std::vector<int>(y, 0));
	entity_map = fill;
}