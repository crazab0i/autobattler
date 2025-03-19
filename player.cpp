#include "player.h"


void Player::changeGold(int diffGold) {
		this->gold += diffGold;
}
const int Player::getGold() {
	return this->gold;
}

void Player::addItem(Item item) {
	playerItemInventory.push_back(item);
	itemAttack += item.getAttack();
	itemHealth += item.getHealth();
	itemMana += item.getMana();
	itemManaGeneration += item.getManaGeneration();
	itemPower += item.getPower();
}

void Player::printPlayerInventory() {
	for (size_t i = 0; i < playerItemInventory.size(); i++) {
		playerItemInventory[i].printItemStats();
		std::cout << std::endl;
	}
}


void Player::changeMaxHealth(double maxhealth) {
	setMaxHealth(getMaxHealth() + maxhealth);
}
void Player::changeAttack(double attack) {
	setAttack(getAttack() + attack);
}
void Player::changeMana(double mana) {
	setMana(getMana() + mana);
}
void Player::changeManaGeneration(double manaGeneration) {
	setManaGeneration(getManaGeneration() + manaGeneration);
}
void Player::changePower(double power) {
	setPower(getPower() + power);
}