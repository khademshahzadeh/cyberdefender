#include"player.h"
#include <ctime>
player::player() {
	health = 3;
	score = 0;
	time = time(NULL);
}

void 
player::lose() {
	health--;
}

void 
player::win() {
	score++;
};