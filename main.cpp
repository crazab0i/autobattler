
#include "mobs.h"
#include "player.h"
#include "simulation.h"

#include <iostream>

int main() {
	clearConsole();
	welcome();
	Player player = createPlayer();
	battle(player);
	return 0;
}