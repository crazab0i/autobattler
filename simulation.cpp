#include "simulation.h"

void clearConsole() {
	system("clear");
}
void delay(int miliseconds) {
	std::this_thread::sleep_for(std::chrono::milliseconds(miliseconds));
}

void welcome() {
	std::cout << "Welcome to Ascension" << std::endl;
}
Player createPlayer() {
	std::cout << "Welcome to character creator" << "\n";
	std::string name;
	std::cout << "Enter a name" << "\n";
	std::cin >> name;
	Player player(name);
	return player;
}

void battle(Player &player) {
	clearConsole();
	resetPlayer(player);
	Warrior warrior;
	while (warrior.isAlive() && player.isAlive()) {
		stepThrough(player, warrior);
	}
	std::cout << "Battle End " << "\n";
	player.printStats();
}

void stepThrough(Player &player, Warrior &warrior) {
	player.basicAttack(warrior);
	delay(500);
	if (warrior.isAlive()) {
		warrior.basicAttack(player);
		delay(500);
		if (!player.isAlive()) {
			player.death();
		}
	} else {
		warrior.death();
	}
}
void resetPlayer(Player &player) {
	
}