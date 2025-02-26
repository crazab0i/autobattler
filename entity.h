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

	Entity(std::string name, double health, double attack, double mana, double manaGeneration, bool alive, std::vector<Ability> abilities) 
		:name(name), maxHealth(health), currentHealth(health), attack(attack), mana(mana), manaGeneration(manaGeneration), alive(alive), abilities(abilities) {}

	std::string getName() const;
	void addAbility(std::string ability, std::string ability_desc, std::vector<double> ability_stats);
	void printStats() const;

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