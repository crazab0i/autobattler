#ifndef PLAYER_H
#define PLAYER_H 

#include "entity.h"

#include <string>
#include <vector>


class Player : public Entity {
	private:
	public:
		Player(std::string name)
			: Entity(name, 20, 2, 0, 0.5, true) {}
		
		template <typename T>
		void basicAttack(T &target) {
			std::cout << "\033[1;37m" << getName() << "\033[0m" << " attacks " << "\033[1;31m" << target.getName() << "\033[0m" << " for " << "\033[1;38;5;88m" << getAttack() << " damage." << "\033[0m" << "\n";
			target.modifyHealth(-getAttack());
			target.isAlive();
	}
};

#endif