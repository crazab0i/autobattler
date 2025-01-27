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

void resetPlayer(Player &player) {
	player.setCurrentHealth(player.getMaxHealth());
}