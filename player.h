#pragma once
#include "timer.h"
class player {
private:
	int score;
	int health;
	Timer time;
public:
	player(){}
	void lose();
	void win();
};