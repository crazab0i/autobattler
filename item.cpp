#include "item.h"

double Item::getValue() {
	return this->value;
}
double Item::getAttack() {
	return this->attack;
} 
double Item::getHealth() {
	return this->health;
}
double Item::getMana() {
	return this->mana;
}
double Item::getManaGeneration() {
	return this->manaGeneration;
}
double Item::getPower() {
	return this->power;
}
std::string Item::getName() {
	return this->name;
}


void Item::printItemStats() {
	std::vector<double> active_stats;
	int nameLength = this->getName().length();
	int width;

	if (nameLength % 2 == 0) {
		width = 50;
	} else {
		width = 51;
	}

	std::cout << std::string(width, '*') << "\n";
	std::cout << "\n";
	std::cout << std::string(((width - this->getName().length()) / 2), ' ') << '+' << std::string(nameLength, '-') << '+' << '\n';
	std::cout << std::string(((width - this->getName().length()) / 2), ' ') << '|' << this->getName() << '|' << std::string(((width - this->getName().length()) / 2 - 1), ' ') << "\n";
	std::cout << std::string(((width - this->getName().length()) / 2), ' ') << '+' << std::string(nameLength, '-') << '+' << '\n';
	std::cout << "\n";
	std::cout << std::string(((width - this->getName().length()) / 2 + 2), ' ') << "Value: " << this->getValue() << "\n";
	if (this->getAttack() != 0) {
		std::cout << std::string(((width - this->getName().length()) / 2 + 2), ' ') << "Attack: " << this->getAttack() << "\n";
	}
	if (this->getHealth() != 0) {
		std::cout << std::string(((width - this->getName().length()) / 2 + 2), ' ') << "Health: " << this->getHealth() << "\n";
	}
	if (this->getMana() != 0) {
		std::cout << std::string(((width - this->getName().length()) / 2 + 2), ' ') << "Mana: " << this->getMana() << "\n";
	}
	if (this->getManaGeneration() != 0) {
		std::cout << std::string(((width - this->getName().length()) / 2 + 2), ' ') << "Mana Generation: " << this->getManaGeneration() << "\n";
	}
	if (this->getPower() != 0) {
		std::cout << std::string(((width - this->getName().length()) / 2 + 2), ' ') << "Power: " << this->getPower() << "\n";
	}
	std::cout << "\n";
	std::cout << std::string(width, '*') << "\n";
	
}