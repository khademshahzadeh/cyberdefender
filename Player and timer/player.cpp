#include"player.h"
#include <ctime>
#include <iostream>
using namespace std;

player::player() {
	health = 3;
	score = 0;
}

void 
player::lose() {
	health--;
	if(health == 0)
		endgame();
}

void 
player::win() {
	score++;
	if(score == 5)
		endgame();
};
void
player::endgame(){
	if(health == 0){
		cout << endl <<" You have lost your chances, YOU LOSE" << endl;
		return;
		}
		
	if(score == 5){
		cout << endl << "You have won every game with out losing a single game congratualation on your perfect win"<<endl;
		return;
	}
	int lostgames = 3 - health;
	if(score > lostgames){
		cout << "You have won " << score << " from "<< score + lostgames << " YOU WON " << endl;
		return;
		}
}