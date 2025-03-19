#include "shop.h"
#include "player.h"

int main() {
	/*
	Item bork(10, 10, 0, 0, 0, 5, "Blade of the Ruined King");
	bork.printItemStats();
	return 0;
	*/
	Player craza("craza");
	Shop shop1(&craza);
	craza.changeGold(20);
	shop1.print_shop();
	craza.printPlayerInventory();
	craza.printStats();
	return 0;
}