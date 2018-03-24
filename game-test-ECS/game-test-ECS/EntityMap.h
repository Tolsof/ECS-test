#pragma once
#include <vector>

class EntityMap {
	std::vector<std::vector<int>> entity_map;

public:
	EntityMap(int x, int y);

	int getGUID(int x, int y) const;
	void setGUID(int x, int y, int guid);
	void clearLoc(int x, int y);
};