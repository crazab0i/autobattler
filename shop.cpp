#include "shop.h"

void Shop::print_shop() {
	int length = static_cast<int>(items.size()) - 1;
	int pos = 0;
	char letter;
	while (true) {
		length = static_cast<int>(items.size()) - 1;
		if (length == -1) {
			system("clear");
			std::cout << "Empty Shop" << std::endl;
			break;
		}
		system("clear");
		items[pos].printItemStats();
		letter = getKeyPress();
		system("clear");
		if (letter == 'q') {
			system("clear");
			break;
		}
		if (pos == 0 && letter == 'd') {
			pos++;
			continue;
		}
		if (pos == length && letter == 'a') {
			pos--;
			continue;
		}
		if (pos > 0 && pos < length) {
			if (letter == 'd') {
				pos++;
				continue;
			} 
			if (letter == 'a') {
				pos--;
				continue;
			}
		}
		if (letter == 'b') {
			buy_item(pos);
			std::cout << "Bought Item" << std::endl;
			if (pos == length && pos > 0) {
				pos--;
			}
		}
	}


	//empty shop
	//buy feature (if pos == 0 and items is length 0 after pop, print empty shop)
	
}

void Shop::buy_item(int pos) {
	Item item = items[pos];
	items.erase(items.begin() + pos);
	player->addItem(item);
}