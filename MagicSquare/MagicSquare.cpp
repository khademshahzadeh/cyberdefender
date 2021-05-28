#include <iostream>
#include <string>
#include <iomanip>
#include "Magicsquare.h"


		
	
		void MagicSquare::game(){
			print();
			
			while(key=1){
				playermove();
				print();
				checkWin();				
			}
			
		}
		void MagicSquare::playermove(){
			char c;
			cin>>c;
			if(c=='0')
			{printboard();return;}
			int i=10,j=10;
			for(int x=0;x<3;x++){
			  for (int y=0;y<3;y++){
				if (c==board[x][y])
				{i=x;j=y;}
		}}
				 if (i==10 && j==10 && c!=board[2][2])//peyda nakard
				{cout<<"wrong input\n";print();playermove();return;	}

				int o;
				cin>>o;
				if(o>9 ||o<1){
				cout<<"wrong input\n";print();playermove();return;	
				}
				display[i][j]=to_string(o); places[i][j]=o;
		}
		
		void MagicSquare::checkWin(){
			int win=0;
			bool check=1;
		for (int i=0;i<8;i++){		
			if( places[list[i][0]][list[i][3]] + places[list[i][1]][list[i][4]] + places[list[i][2]][list[i][5]] ==15){
			win+=1;}}
			
			for(int x=0;x<3;x++){//adade tekrari nabashe
			for(int y=0;y<3;y++){
				for(int xp=0;xp<3;xp++){
				for(int yp=0;yp<3;yp++){
				 if(display[x][y]==display[xp][yp] && !(x==xp && y==yp)){
					check=0;
				 }									
				}}	
				}}	
					
		if(win==8 && check==1){
			cout<<"\nwon\n";print();resault=1;key=0;}
		}
		
		void MagicSquare::print(){	
		cout<<endl;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				cout<<left<<setw(3)<<display[i][j];
			}
			cout<<endl;
		}	
		cout<<endl;
		}
		
		void MagicSquare::printboard(){	
		cout<<endl<<"The board is:\n";
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				cout<<left<<setw(3)<<board[i][j];
			}
			cout<<endl;
		}	
		cout<<endl<<"_________\n";
		}
		

