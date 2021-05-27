#pragma once
#include <ctime>
class Timer {
private:
	struct tm y;
	int currenttime;
public:
	Timer(int hour, int min, int s);
	void display();
};