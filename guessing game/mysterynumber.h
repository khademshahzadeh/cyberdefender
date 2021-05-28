#pragma once

class Mysterynumber {
private:	
	bool digcom(int);
	bool find(int);
	int grd();
	static int chance;
	int* digits;
	int* guessed;
public:
	Mysterynumber();
	bool game();
	~Mysterynumber();
};


