#ifndef X_O_H
#define X_O_H
#include "x_oClass.h"
#include<iostream>
//#inlude"x_o.cpp"
using namespace std;
	//methods:
void x_o::game(){
			while(key==1){
				print();
				newmove();
				print();
				check_winner();
				AImove();
				check_winner();		
			}
	}
void
x_o::print(){
			for(int i=0;i<3;i++){
			for(int j=0;j<3;j++)
				cout<<display[i][j]<<' ';					
		cout<<endl;
		} cout<<endl;
		}
void 
x_o::AImove(){
			cout<<"AI has placed an 'O': \n";
			/*algoritm estefade shode be in shekle ke 
			too araye places be ezaye X->2 va be ezaye y->3 mizare
			bad bar asase olaviat ha jaye Oro mizarim 
			*/
			//let AI win O O _
				for (int i=0;i<8;i++){		
						if( places[list[i][0]][list[i][3]] * places[list[i][1]][list[i][4]] * places[list[i][2]][list[i][5]] ==9){
				// cout<<"48\n";		
						if ( places[list[i][0]][list[i][3]]==1)
						{places[list[i][0]][list[i][3]]=3 ;display[list[i][0]][list[i][3]]='O';	return ;}	
						if ( places[list[i][1]][list[i][4]]==1)
						{places[list[i][1]][list[i][4]]=3 ;display[list[i][1]][list[i][4]]='O';	return ;}	
						if ( places[list[i][2]][list[i][5]]==1)
						{places[list[i][2]][list[i][5]]=3 ;display[list[i][2]][list[i][5]]='O';	return ;}						
						}					
				}
				
			//prevent losing: X X _ 
				for (int i=0;i<8;i++){		
						if( places[list[i][0]][list[i][3]] * places[list[i][1]][list[i][4]] * places[list[i][2]][list[i][5]] ==4){
				// cout<<"61\n";
						if ( places[list[i][0]][list[i][3]]==1)
						{places[list[i][0]][list[i][3]]=3 ;display[list[i][0]][list[i][3]]='O';return ;	}	
						if ( places[list[i][1]][list[i][4]]==1)
						{places[list[i][1]][list[i][4]]=3 ;display[list[i][1]][list[i][4]]='O';return ;	}	
						if ( places[list[i][2]][list[i][5]]==1)
						{places[list[i][2]][list[i][5]]=3 ;display[list[i][2]][list[i][5]]='O';return ;	}						
						}					
				}
			// 1 O 2 empty: O _ _
				for (int i=0;i<8;i++){		
						if( places[list[i][0]][list[i][3]] * places[list[i][1]][list[i][4]] * places[list[i][2]][list[i][5]] ==3){
				// cout<<"73\n";
						if ( places[list[i][0]][list[i][3]]==1)
						{places[list[i][0]][list[i][3]]=3 ;display[list[i][0]][list[i][3]]='O';	return ;}	
						if ( places[list[i][1]][list[i][4]]==1)
						{places[list[i][1]][list[i][4]]=3 ;display[list[i][1]][list[i][4]]='O';	return ;}	
						if ( places[list[i][2]][list[i][5]]==1)
						{places[list[i][2]][list[i][5]]=3 ;display[list[i][2]][list[i][5]]='O';return ;	}						
						}					
				}
			// 1 x 2 empty: X _ _								
				for (int i=0;i<8;i++){		
						if( places[list[i][0]][list[i][3]] * places[list[i][1]][list[i][4]] * places[list[i][2]][list[i][5]] ==2){
				// cout<<"85\n";
						if ( places[list[i][0]][list[i][3]]==1)
						{places[list[i][0]][list[i][3]]=3 ;display[list[i][0]][list[i][3]]='O';	return ;}	
						if ( places[list[i][1]][list[i][4]]==1)
						{places[list[i][1]][list[i][4]]=3 ;display[list[i][1]][list[i][4]]='O';	return ;}	
						if ( places[list[i][2]][list[i][5]]==1)
						{places[list[i][2]][list[i][5]]=3 ;display[list[i][2]][list[i][5]]='O';return ;	}						
						}					
				}
			//3 empty: _ _ _		
				for (int i=0;i<8;i++){		
						if( places[list[i][0]][list[i][3]] * places[list[i][1]][list[i][4]] * places[list[i][2]][list[i][5]] ==1){
				// cout<<"97\n";		
						if ( places[list[i][0]][list[i][3]]==1)
						{places[list[i][0]][list[i][3]]=3 ;display[list[i][0]][list[i][3]]='O';	return ;}	
						if ( places[list[i][1]][list[i][4]]==1)
						{places[list[i][1]][list[i][4]]=3 ;display[list[i][1]][list[i][4]]='O';	return ;}	
						if ( places[list[i][2]][list[i][5]]==1)
						{places[list[i][2]][list[i][5]]=3 ;display[list[i][2]][list[i][5]]='O';return ;	}						
						}					
				}	
			//1 x 1 o : X O _
			for (int i=0;i<8;i++){		
						if( places[list[i][0]][list[i][3]] * places[list[i][1]][list[i][4]] * places[list[i][2]][list[i][5]] ==6){
				// cout<<"109\n";			
						if ( places[list[i][0]][list[i][3]]==1)
						{places[list[i][0]][list[i][3]]=3 ;display[list[i][0]][list[i][3]]='O';	return ;}	
						if ( places[list[i][1]][list[i][4]]==1)
						{places[list[i][1]][list[i][4]]=3 ;display[list[i][1]][list[i][4]]='O';	return ;}	
						if ( places[list[i][2]][list[i][5]]==1)
						{places[list[i][2]][list[i][5]]=3 ;display[list[i][2]][list[i][5]]='O';return ;	}						
						}					
				}
		//		cout<<"ai func is done\n"				;
		}
		
void
x_o::newmove(){
			if(key==1){
			char  nm;
			cin>>nm;
			for (int i=0;i<3;i++)
				for (int j=0;j<3;j++)
					if (nm==board[i][j] && display[i][j] !='X' && display[i][j] !='O'){
						display[i][j]='X';
						places [i][j]=2;
						return ;
					}
			cout<<"something went wrong !try another cell"<<endl;
			newmove();
		}
		}
	
		void 
		x_o::check_winner(){
						for (int i=0;i<8;i++){		
						if( places[list[i][0]][list[i][3]] * places[list[i][1]][list[i][4]] * places[list[i][2]][list[i][5]] ==27)
							{key=0; winner='O';call_winner();return;}
				}
						for (int i=0;i<8;i++){		
						if( places[list[i][0]][list[i][3]] * places[list[i][1]][list[i][4]] * places[list[i][2]][list[i][5]] ==8)
							{key=0; winner='X';call_winner();return;}
				}
				if(places[0][0] !=1 && places[0][2] !=1 && places[0][1] !=1
				&& places[1][0] !=1 && places[1][2] !=1 && places[1][1] !=1
				&& places[2][0] !=1 && places[2][2] !=1 && places[2][1] !=1)	
			{key=0; winner='D';call_winner();return;}
		
	}
		
	void
		x_o::call_winner(){
		cout<<"the resault is:";
		switch(winner){
		case 'X':cout<<"win\n"; ; key=0;resault=1; print(); return;//cout<<"		win\n";
		case 'O':cout<<"loose\n";key=0;resault=0;print(); return;//cout<<"			loose\n";
		case 'D':cout<<"draw\n";key=0;resault=1;print();return;//cout<<"				draw\n";
		}
		exit;
	}

#endif
