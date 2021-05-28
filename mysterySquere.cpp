#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

class sudoku{
	public:
	//attributes:
		string display[3][3]={{"a","b","c"},{"d","e","f"},{"g","h","i"}};
		char board[3][3]={{'a','b','c'},{'d','e','f'},{'g','h','i'}};
		int places[3][3]={{0,0,0},{0,0,0},{0,0,0}};
		
		int list[6][6]=
		{{0,0,0, 0,1,2},{1,1,1, 0,1,2},{2,2,2, 0,1,2}//vertical cells addresses {}
		,{0,1,2, 0,0,0},{0,1,2, 1,1,1},{0,1,2, 2,2,2}//horizonal cells addresses
		};
		
		bool key=1;
		bool resault=1;
		int t=7;
	//methods:
		void game(){
			setDefault();	
			setDefault();	
			setDefault();
			testDefault();
			print();
			while(key=1){
				playermove();
				print();
				checkWin();				
			}
			
		}
		void playermove(){
			char c;
			cin>>c;
			int i=10,j=10;
			for(int x=0;x<3;x++){
			  for (int y=0;y<3;y++){
				if (c==board[x][y])
				{i=x;j=y;}
		}}
				 if (i==10 && j==10 && c!=board[2][2])//peyda nakard
				{cout<<"wrong input\n";print();playermove();return;	}
				
				if(display[i][j]=="1*"||display[i][j]=="2*"||display[i][j]=="3*"){
					cout<<"this cell has already been filled try another cell\n";print();playermove();return;	
				}
				int o;
				cin>>o;
				if(o>3 ||o<1){
				cout<<"wrong input\n";print();playermove();return;	
				}
				display[i][j]=to_string(o); places[i][j]=o;
		}
		
		void checkWin(){
			int win=0;
		for (int i=0;i<6;i++){		
			if( places[list[i][0]][list[i][3]] * places[list[i][1]][list[i][4]] * places[list[i][2]][list[i][5]] ==6){
			win+=1;}}
		if(win==6){
			cout<<"\nwon\n";print();resault=1;key=0;}
		}
		
		void setDefault(){				
			int i,j,k;
			srand((time(0)+t*3));
			i=rand()%3; 
			srand((time(0)+t));
			j=rand()%3; 		
			srand((time(0)+t+10));
			k=(rand() )%3 +1; 
			if(k<0)
				k=(-1)*k;
			if(i<0)
				i=(-1)*i;
			if(j<0)
				j=(-1)*j;
										
			if(places[i][j]!=0)//por bood
			{setDefault();return ;}
			
			for (int y=0;y<3;y++){//oon radif ya sotoon daasht
				if (places[y][j]==k && y!=i)
				{setDefault();return ;}}
			for (int y=0;y<3;y++){
				if (places[i][y]==k && y!=j)
				{setDefault();return ;}}				
			
			places[i][j]=k;
			display[i][j]=to_string(k)+"*";//??cout<<"46";
			for(int p=0;p<6;p++){//oon radifaayi ke 2tashoon pore , 3omishoono bayad havasemoon besh baashe
				if(places[list[p][0]] [list[p][3]]!=0 && places[list[p][1]] [list[p][4]]!=0){
					switch(places[list[p][0]] [list[p][3]] * places[list[p][1]] [list[p][4]]){
						case (2):places[list[p][2]] [list[p][5]]=3;cout<<"99 ";//1 o 2
						case (3):places[list[p][2]] [list[p][5]]=2;cout<<"100 ";//1 o 3
						case (6):places[list[p][2]] [list[p][5]]=1;cout<<"101 ";//3 o 2
					}}
				
				if(places[list[p][0]] [list[p][3]]!=0 && places[list[p][2]] [list[p][5]]!=0){
					switch(places[list[p][0]] [list[p][3]] * places[list[p][2]] [list[p][5]]){
						case (2):places[list[p][1]] [list[p][4]]=3;cout<<"106 ";//1 o 2
						case (3):places[list[p][1]] [list[p][4]]=2;cout<<"107 ";//1 o 3
						case (6):places[list[p][1]] [list[p][4]]=1;cout<<"108 ";//3 o 2
					}}
				
				if(places[list[p][1]] [list[p][4]]!=0 && places[list[p][2]] [list[p][5]]!=0){
					switch(places[list[p][1]] [list[p][4]] * places[list[p][2]] [list[p][5]]){
						case (2):places[list[p][0]] [list[p][3]]=3;cout<<"113 ";//1 o 2
						case (3):places[list[p][0]] [list[p][3]]=2;cout<<"114 ";//1 o 3
						case (6):places[list[p][0]] [list[p][3]]=1;cout<<"115 ";//3 o 2
					}}//cout<<"7 ";
			}
			int xpp,ypp;
			for(int x=0;x<3;x++){
			for(int y=0;y<3;y++){
				for(int xp=0;xp<3;xp++){
				for(int yp=0;yp<3;yp++){
				 if(display[x][y]==display[xp][yp] && !(x==xp && y==yp)){
					for(int q;q<3;q++){
					if(q!=x && q!=xp)
						xpp=q;
					if(q!=y && q!=yp)
						ypp=q;	
					}
					if(places[xpp][ypp]!=0){
						places[xpp][ypp]=places[x][y];
						display[xpp][ypp]=display[x][y];
					}		
					}				
				}}	
				}}
			t=t*3%7 +1;
		}
		
		
		void print(){	
		cout<<endl;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				cout<<left<<setw(3)<<display[i][j];
			}
			cout<<endl;
		}	
		}
		
		void testDefault(){
			for(int p=0;p<6;p++){//oon radifaayi ke 2tashoon pore , 3omishoono bayad havasemoon besh baashe
			if(places[list[p][0]] [list[p][3]]!=0 && places[list[p][1]] [list[p][4]]!=0 && 
				places[list[p][1]] [list[p][4]]==places[list[p][0]] [list[p][3]]){
				if(display[list[p][1]] [list[p][4]]=="1*"){display[list[p][1]] [list[p][4]].
				pop(1);display[list[p][1]] [list[p][4]].pop(1);display[list[p][1]] [list[p][4]].append(1,board[list[p][1]] [list[p][4]]);}					
				if(display[list[p][1]] [list[p][4]]=="2*"){display[list[p][1]] [list[p][4]].pop_back();
				display[list[p][1]] [list[p][4]].pop_back();display[list[p][1]] [list[p][4]].append(1,board[list[p][1]] [list[p][4]]);}
				if(display[list[p][1]] [list[p][4]]=="3*"){display[list[p][1]] [list[p][4]].pop_back(1,board[list[p][1]] [list[p][4]]);
				display[list[p][1]] [list[p][4]].pop_back();list[p][4]].append(1,board[list[p][1]] [list[p][4]]);}
				if(display[list[p][0]] [list[p][3]]=="1*"){{display[list[p][0]] [list[p][3]].pop_back();
				list[p][3]].pop_back();display[list[p][0]] [list[p][3]].append(1,board[list[p][0]] [list[p][3]]);}					
				if(display[list[p][0]] [list[p][3]]=="2*"){display[list[p][0]] [list[p][3]].pop_up();
				list[p][3]].pop_up();display[list[p][0]] [list[p][3]].append(1,board[list[p][0]] [list[p][3]]);}
				if(display[list[p][0]] [list[p][3]]=="3*"){display[list[p][0]] [list[p][3]].pop_back();
				list[p][3]].pop_back();display[list[p][0]] [list[p][3]].append(1,board[list[p][0]] [list[p][3]]);}
			}
			if(places[list[p][0]] [list[p][3]]!=0 && places[list[p][2]] [list[p][5]]!=0 && 
				places[list[p][2]] [list[p][5]]==places[list[p][0]] [list[p][3]]){	
				if(display[list[p][2]] [list[p][5]]=="1*"){display[list[p][1]] [list[p][4]].append(1,board[list[p][2]] [list[p][5]]);}					
				if(display[list[p][2]] [list[p][5]]=="2*"){display[list[p][1]] [list[p][4]].append(1,board[list[p][2]] [list[p][5]]);}
				if(display[list[p][2]] [list[p][5]]=="3*"){display[list[p][1]] [list[p][4]].append(1,board[list[p][2]] [list[p][5]]);}
				if(display[list[p][0]] [list[p][3]]=="1*"){display[list[p][0]] [list[p][3]].append(1,board[list[p][0]] [list[p][3]]);}					
				if(display[list[p][0]] [list[p][3]]=="2*"){display[list[p][0]] [list[p][3]].append(1,board[list[p][0]] [list[p][3]]);}
				if(display[list[p][0]] [list[p][3]]=="3*"){display[list[p][0]] [list[p][3]].append(1,board[list[p][0]] [list[p][3]]);}
			}
			if(places[list[p][1]] [list[p][4]]!=0 && places[list[p][2]] [list[p][5]]!=0 && 
				places[list[p][2]] [list[p][5]]==places[list[p][1]] [list[p][4]]){	
				if(display[list[p][2]] [list[p][5]]=="1*"){display[list[p][2]] [list[p][5]].append(1,board[list[p][2]] [list[p][5]]);}					
				if(display[list[p][2]] [list[p][5]]=="2*"){display[list[p][2]] [list[p][5]].append(1,board[list[p][2]] [list[p][5]]);}
				if(display[list[p][2]] [list[p][5]]=="3*"){display[list[p][2]] [list[p][5]].append(1,board[list[p][2]] [list[p][5]]);}
				if(display[list[p][1]] [list[p][4]]=="1*"){display[list[p][1]] [list[p][4]].append(1,board[list[p][1]] [list[p][4]]);}					
				if(display[list[p][1]] [list[p][4]]=="2*"){display[list[p][1]] [list[p][4]].append(1,board[list[p][1]] [list[p][4]]);}
				if(display[list[p][1]] [list[p][4]]=="3*"){display[list[p][1]] [list[p][4]].append(1,board[list[p][1]] [list[p][4]]);}
			}

				
				}
				
			
					int xpp,ypp;
			for(int x=0;x<3;x++){
			for(int y=0;y<3;y++){
				for(int xp=0;xp<3;xp++){
				for(int yp=0;yp<3;yp++){
				 if(places[x][y]==places[xp][yp] && places[x][y]!=0 && !(x==xp && y==yp)){
					for(int q;q<3;q++){
					if(q!=x && q!=xp)
						xpp=q;
					if(q!=y && q!=yp)
						ypp=q;	
					}
					if(places[xpp][ypp]!=0){
						places[xpp][ypp]=places[x][y];
						display[xpp][ypp]=display[x][y];
					}		
					}				
				}}	
				}}
		}}
};

int main() {
sudoku ali;
ali.game();
return 4;
system("pause");
}
