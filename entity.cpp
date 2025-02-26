#include "entity.h" 



std::string Entity::getName() const {
	return this->name;
}

void Entity::addAbility(std::string ability, std::string ability_desc, std::vector<double> ability_stats) {
	this->abilities.push_back({ability, ability_desc, ability_stats});
}
void Entity::printStats() const {
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


void Entity::setMaxHealth(double maxHealth) {
	this->maxHealth = maxHealth;
}
void Entity::setCurrentHealth(double health) {
	this->currentHealth = health;
}
void Entity::modifyHealth(double changeInHealth) {
	this->currentHealth += changeInHealth;
	if (this->currentHealth <= 0) {
		setAlive(false);
	}
}
double Entity::getMaxHealth() const {
	return this->maxHealth;
}

double Entity::getCurrentHealth() const {
	return this->currentHealth;
}
bool Entity::isAlive() const {
	return this->alive;
}
void Entity::setAlive(bool alive) {
	this->alive = alive;
}
void Entity::death() {
	std::vector<std::string> deathMessages {" has died.", "has perished.", " is no more.", " has been befelled.", " has fallen.", " breathed their last breath.",
		" has succumbed to their injuries.", " met their untimely end.", " was sent to the afterlife.", " has been vanquished.", " took their final breath.",
    " will fight no more.", " fell in the heat of battle.", " has crossed over to the other side.", " was struck down."," couldn't withstand the blow.",
    " has been obliterated.", " is now one with the void.", " was claimed by the reaper.", " has departed from this world.", " has left us forever.",
    " will be remembered in legends.", " has been silenced forever.", " has fallen, never to rise again.", " faced their demise.", " was extinguished like a dying flame."};
	static std::random_device rd;
	static std::mt19937 mt(rd());
	static std::uniform_int_distribution<> dist(0, deathMessages.size() - 1);

	if (!isAlive()) {
		std::cout << this->getName() << deathMessages[dist(mt)] + "\n";
	}
}


void Entity::setMana(double mana) {
	this->mana = mana;
}
void Entity::modifyMana(double changeInMana) {
	this->mana += changeInMana;
}
double Entity::getMana() const {
	return this->mana;
}
double Entity::getManaGeneration() const{
	return this->manaGeneration;
}

void Entity::setManaGeneration(double manaGeneration) {
	this->manaGeneration += manaGeneration;
}


void Entity::progress() {

}
void Entity::useAbility() {

}

double Entity::getAttack() const {
	return this->attack;
}

double Entity::setAttack(double attack) {
	this->attack += attack;
}


double Entity::getPower() const {
	return this->power;
}

void Entity::setPower(double power) {
	this->power += power;
}