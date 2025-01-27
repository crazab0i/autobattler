#ifndef BATTLE_H
#define BATTLE_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>

#include "entity.h"
#include "mobs.h"
#include "player.h"

class Battle {
	private:
	std::vector<std::unique_ptr<Entity>> mobs;
	int difficultyRating = 0;

	void generateBattleReward(Player &player);
	void generateDifficultyRating();
	public:

	Battle() {
		mobs.push_back(std::make_unique<Warrior>());
		difficultyRating = 1;
	}
	Battle(std::vector<std::unique_ptr<Entity>> mobs)
		: mobs(std::move(mobs)), difficultyRating(10) {}

	void addMobs(std::vector<std::unique_ptr<Entity>> mobs);

	void simulateBattle(Player &player);

	Entity& accessMob(size_t index) {
		return *this->mobs[index];
	}

	size_t sizeOfMObs() {
		return mobs.size();
	}
};


#endif