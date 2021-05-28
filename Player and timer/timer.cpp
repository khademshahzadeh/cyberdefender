#include "timer.h"


Timer::Timer(int hour, int min, int s) {
	y.tm_hour = hour;
	y.tm_min = min;
	y.tm_sec = s;
	currenttime = time(NULL)
}
void
Timer::display() {
	int h = difftime(currenttime, y) / 3600;
	int m = difftime(currenttime, y) / 60 - (h * 60);
	int s = difftime(currenttime, y) - (h * 3600) - (m * 60);
	cout << "timer : " << h << " : " << "m" << " : " << "s" << endl;
}