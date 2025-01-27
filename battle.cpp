
#include "battle.h"
#include "simulation.h"


void Battle::addMobs(std::vector<std::unique_ptr<Entity>> mobs) {
		for (size_t i = 0; i < mobs.size(); i++) {
			this->mobs.push_back(std::move(mobs[i]));
		}
	}


void Battle::simulateBattle(Player &player) {
	clearConsole();
	resetPlayer(player);
	size_t index = 0;
	while (player.isAlive() && index < this->sizeOfMObs()) {
		
		Entity &current_mob = this->accessMob(index);
		while (current_mob.isAlive()) {
			player.basicAttack(current_mob);
			delay(500);
			if (current_mob.isAlive()) {
				current_mob.basicAttack(player);
				delay(500);
			}
			current_mob.death();
		}
		index ++;
	}
	if (player.isAlive()) {
		std::cout << "Player wins" << "\n";
	} else {
		player.death();
		std::cout << "Player loses" << "\n";
	}
	player.printStats();
}

void Battle::generateBattleReward(Player &player) {
	player.changeGold(this->difficultyRating * 10);
}