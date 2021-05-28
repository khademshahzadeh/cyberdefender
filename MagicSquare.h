#include <iostream>
#include <string>
#include <iomanip>
#ifndef MAGICSQUARE_H
#define MAGICSQUARE_H
using namespace std;
class MagicSquare{
	public:
	//attributes:
		string display[3][3]={{"a","b","c"},{"d","e","f"},{"g","h","i"}};
		char board[3][3]={{'a','b','c'},{'d','e','f'},{'g','h','i'}};
		int places[3][3]={{0,0,0},{0,0,0},{0,0,0}};
		
		int list[8][6]=
		{{0,0,0, 0,1,2},{1,1,1, 0,1,2},{2,2,2, 0,1,2}//vertical cells addresses {}
		,{0,1,2, 0,0,0},{0,1,2, 1,1,1},{0,1,2, 2,2,2}//horizonal cells addresses
		,{0,1,2, 0,1,2},{0,1,2, 2,1,0}//inclined cells addresses
		};
		
		bool key=1;
		bool resault=0;
	//methods:
		void game();
		
		void playermove();
		
		void checkWin();
		
		void print();
		
		void printboard();
		
};
#endif
