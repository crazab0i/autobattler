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
		std::cout << player->getGold() << "\n";
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
			//std::cout << "b pressed";
			//std::this_thread::sleep_for(std::chrono::seconds(2));
			if (buy_item(pos)) {
				if (pos == length && pos > 0) {
					pos--;
				}
			}
		}
	}


	//empty shop
	//buy feature (if pos == 0 and items is length 0 after pop, print empty shop)
	
}

bool Shop::buy_item(int pos) {
	Item item = items[pos];
	if (item.getValue() > player->getGold()) {
		while (true) {
			system("clear");
			std::cout << "Not Enough Gold!!! \npress q to continue" << "\n";
			char letter;
			letter = getKeyPress();
			if (letter == 'q') {
				break;
			}
		}
		return false;
	}
	items.erase(items.begin() + pos);
	player->addItem(item);
	player->changeGold(-item.getValue());
	system("clear");
	std::cout << "Bought Item " << item.getName() << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	return true;
}