#include "timer.h"
#include <iostream>
#include <iomanip>

using namespace std;

Timer::Timer() {
	h = 0;
	m = 5;
	s = 0;
}
void
Timer::display() {
	cout << setfill('0') << setw(2) << h;
	cout <<" : " << setfill('0') << setw(2) << m;
	cout <<" : " << setfill('0') << setw(2) << s << endl;
	tick();
}
void 
Timer::tick(){
	if(s == 0){
		if(m == 0){
			if(h == 0)
				Alert();
			else
			{
				h--;
				m += 59;
				s += 59;
			}
		}
		else
		{
			m--;
			s += 59;
		}
	}
	else{
		s--;
	}
}
void
Timer::Alert(){
	cout << "Time had ended";
}