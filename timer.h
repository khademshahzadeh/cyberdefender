#pragma once

class Timer {
private:
	int h;
	int m;
	int s; 
	void tick();
	void Alert();
public:
	Timer();
	void display();

};