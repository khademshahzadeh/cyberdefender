#include "mysterynumber.h"
#include "mysterynumber.h"
#include "mysterynumber.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int
Mysterynumber::grd() {
	return (rand() % 9) + 1;
}

int
Mysterynumber::chance = 5;

Mysterynumber::Mysterynumber(){
	chance=5;
	srand(time(0));
	digits = new int[5];
	for (int i = 0; i < 5; i++) {
		digits[i] = grd();
	}
	guessed = new int[4];
	for (int i = 0; i < 4; i++)
		guessed[i] = 0;
	
}

bool
Mysterynumber::digcom(int num) {
	bool r = true;
	for (int i = 4; i >= 0; i--) {
		if (digits[i] != num % 10)
			r = false;
		else {
			for (int j = 0; j < 4; j++) {
				if (guessed[j] == 0) {
					guessed[j] = num % 10;
					break;
				}
			}
		}
		num = num / 10;
	}
	if (r == false)
		chance--;
	return r;
}

bool 
Mysterynumber::game() {
	int a;
	cout << "Enter your guess: " << endl;
	cin >> a;
	bool b = digcom(a);
	if (b) {
		cout << "You guessed right,YOU WON"<< endl;
		return true;
	}
	else {
		if (chance == 0) {
			cout << "You guessed wrong, there is not any chance left" << endl
				// << "Your information is spread in social media" << endl
				<< "You lose." << endl;
			return false;
		}
		else {
			cout << "Wrong guess" << endl
				<< "Correct numbers {";
			if (guessed[0] != 0){
				cout << guessed[0];
				for (int i = 1; i < 4; i++)
					if (guessed[i] != 0)
						cout << ", " << guessed[i];
			}
			cout << "}" << endl;
			cout << "There are only " << chance << " chances left."<<endl;
			for (int i = 0; i < 5; i++) {
				if (find(digits[i]))
					cout << digits[i];
				else
					cout << "_ ";
			}
			cout << endl;
			this->game();
		}
	}
}

Mysterynumber::~Mysterynumber() {
	delete digits;
	delete guessed;
}

bool
Mysterynumber::find(int dig) {
	for (int i = 0; i < 4; i++)
		if (guessed[i] == dig)
			return true;
	return false;
}