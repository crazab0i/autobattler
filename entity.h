#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>
#include <iostream>
#include <random>

struct Ability {
	std::string abilityName;
	std::string abilityDesc;
	std::vector<double> abilityStats;
};

class Entity {
	private:
	std::string name;
	double maxHealth;
	double currentHealth;
	double attack;
	double mana;
	double manaGeneration; 
	bool alive;
	std::vector<Ability> abilities;
	double power;
	double rawPower;
	public:
	virtual ~Entity() {}

	Entity(std::string name, double health, double attack, double mana, double manaGeneration, bool alive) 
		:name(name), maxHealth(health), currentHealth(health), attack(attack), mana(mana), manaGeneration(manaGeneration), alive(alive) {}

	Entity(std::string name, double health, double attack, double mana, double manaGeneration, bool alive, std::vector<Ability> abilities, double power) 
		:name(name), maxHealth(health), currentHealth(health), attack(attack), mana(mana), manaGeneration(manaGeneration), alive(alive), abilities(abilities), power(power) {}

	std::string getName() const; 
	void addAbility(std::string ability, std::string ability_desc, std::vector<double> ability_stats);

	virtual void printStats() const {
	std::cout << "               Name: " << name << "\n";
	std::cout << "         Max Health: " << this->getMaxHealth() << "\n";
	std::cout << "     Current Health: " << this->getCurrentHealth() << "\n";
	std::cout << "             Attack: " << this->getAttack() << "\n";
	std::cout << "               Mana: " << this->getMana() << "\n";
	std::cout << "  Mana regeneration: " <<this->getManaGeneration() << "\n";
	for (size_t i = 0; i < abilities.size(); i++) {
		std::cout << "       Ability name: " << abilities[i].abilityName << "\n";
		std::cout << "Ability description: " << abilities[i].abilityDesc << "\n";
		}
}

	void setMaxHealth(double health);
	void setCurrentHealth(double health);
	void modifyHealth(double changeInHealth);
	double getMaxHealth() const;
	double getCurrentHealth() const;
	bool isAlive() const;
	void setAlive(bool alive);
	void death();

	void setMana(double mana);
	void modifyMana(double changeInMana);
	double getMana() const;
	double getManaGeneration() const;
	void setManaGeneration(double manaGeneration);


	void progress();
	void useAbility();

	virtual void basicAttack(Entity &target) {
		std::cout << this->getName() << " attacks " << target.getName() << " for " << this->getAttack() << " damage." << "\n";
		target.modifyHealth(-getAttack());
		target.isAlive();
	}
	double getAttack() const;
	void setAttack(double attack);
	
	double getPower() const;	
	double calculatePower();
	void setPower(double power); 

	
};

#endif