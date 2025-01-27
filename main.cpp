
#include "mobs.h"
#include "player.h"
#include "simulation.h"
#include "battle.h"

#include <iostream>

int main() {
	clearConsole();
	welcome();
	Player player = createPlayer();
	Battle battle;

	battle.simulateBattle(player);
	return 0;
}