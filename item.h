#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <vector>

class Item {
	private:
	double value;
	double attack;
	double health;
	double mana;
	double manaGeneration;
	double power;
	std::string name;
	public:

	Item(double value, double attack, double health, double mana, double manaGeneration, double power, std::string name) :
	value(value), attack(attack), health(health), mana(mana), manaGeneration(manaGeneration), power(power), name(name) {}


	double getValue();
	double getAttack();
	double getHealth();
	double getMana();
	double getManaGeneration();
	double getPower();
	std::string getName();

	void printItemStats();

};

#endif