#ifndef SIMULATION_H
#define SIMULATION_H

#include "player.h"
#include "mobs.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

void clearConsole();
void delay(int miliseconds);

void welcome();
Player createPlayer();


void battle(Player &player);
void stepThrough(Player &player, Warrior &warrior);
void resetPlayer(Player &player);

#endif