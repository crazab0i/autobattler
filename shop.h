#ifndef SHOP_H
#define SHOP_H
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

#include "item.h"
#include "system.h"
#include "player.h"

class Shop {
	private: 
	int level;
	std::vector<Item> items;
	int selected_index;
	Player* player;
	public:
	Shop(Player* player) : level(1), player(player) {
		items.emplace_back(10, 4, 0, 0, 0, 0, "Simple Sword");
		items.emplace_back(6, 0, 2, 4, 0.5, 0, "Wizard's Ring");
		items.emplace_back(8, 0, 6, 0, 0, 0, "Leafy Coat");
	}

	void print_shop();
	void buy_item(int pos);
};

#endif