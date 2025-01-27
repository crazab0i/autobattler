#ifndef MOBS_H
#define MOBS_H

#include <string>
#include <vector>

#include "entity.h"
#include "player.h"

class Warrior : public Entity {
	private: 
	public:
		Warrior()
			: Entity("Warrior", 10, 2, 0, 0.5, true) {
			addAbility("Swing", "Swings at a target dealing 10dmg. Mana cost: 5", {10, -1, -1, 5});
			}

		Warrior(std::string name, double health, double attack, double mana, double manaGeneration, bool alive)
			: Entity(name, health, attack, mana, manaGeneration, alive) {}
		
		Warrior(std::string name, double health, double attack, double mana, double manaGeneration, bool alive, std::vector<Ability> abilities)
			: Entity(name, health, attack, mana, manaGeneration, alive, abilities) {}
		

		void basicAttack(Entity &player) override {
			std::cout << "\033[1;37m" << getName() << "\033[0m" << " attacks " << "\033[1;31m" << player.getName() << "\033[0m" << " for " << "\033[1;38;5;88m" << getAttack() << " damage." << "\033[0m" << "\n";
			player.modifyHealth(-getAttack());
			player.isAlive();
	}
};



#endif