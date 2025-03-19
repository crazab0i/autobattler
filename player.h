#ifndef PLAYER_H
#define PLAYER_H 

#include "entity.h"
#include "item.h"

#include <string>
#include <vector>
#include <iomanip>


class Player : public Entity {
	private:
	int gold = 0;
	double itemAttack = 0;
	double itemHealth = 0;
	double itemMana = 0;
	double itemManaGeneration = 0; 
	double itemPower = 0;
	std::vector<Item> playerItemInventory;

	public:
	Player(std::string name)
		: Entity(name, 20, 2, 0, 0.5, true, {}, 0) {}
	
	void basicAttack(Entity &target) override {
		std::cout << "\033[1;37m" << getName() << "\033[0m" << " attacks " << "\033[1;31m" << target.getName() << "\033[0m" << " for " << "\033[1;38;5;88m" << getAttack() << " damage." << "\033[0m" << "\n";
		target.modifyHealth(-getAttack());
		target.isAlive();
	}
	void changeGold(int diffGold);
	const int getGold();
	void removeItem(Item item);
	void addItem(Item item);

	void printPlayerInventory();
	virtual void printStats() const {
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "               Name: " << getName() <<  "\n";
	std::cout << "         Max Health: " << getMaxHealth() << " + (" << itemHealth << ")" << "\n";
	std::cout << "     Current Health: " << getCurrentHealth() << " (" << ((getCurrentHealth() / getMaxHealth()) * 100) << "%)" << "\n";
	std::cout << "             Attack: " << getAttack() << " + (" << itemAttack << ")" << "\n";
	std::cout << "               Mana: " << getMana() << " + (" << itemMana << ")" << "\n";
	std::cout << "  Mana regeneration: " << getManaGeneration() << " + (" << itemManaGeneration << ")" << "\n";
	std::cout << "              Power: " << getPower() << " + (" << itemPower << ")" << "\n";
	//for (size_t i = 0; i < abilities.size(); i++) {
	//	std::cout << "       Ability name: " << abilities[i].abilityName << "\n";
	//	std::cout << "Ability description: " << abilities[i].abilityDesc << "\n";
	//	}
	}

	void changeMaxHealth(double maxhealth);
	void changeAttack(double attack);
	void changeMana(double mana);
	void changeManaGeneration(double manaGeneration);
	void changePower(double power);
};

#endif