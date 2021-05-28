class x_o{
public:
	//attributes:

	char display[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
	char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
	int places[3][3] = { {1,1,1},{1,1,1},{1,1,1} };
	int list[8][6] =
	{ {0,0,0, 0,1,2},{1,1,1, 0,1,2},{2,2,2, 0,1,2}//vertical cells addresses {in araye too AImove be kaar miad}
	,{0,1,2, 0,0,0},{0,1,2, 1,1,1},{0,1,2, 2,2,2}//horizonal cells addresses
	,{0,1,2, 0,1,2},{0,1,2, 2,1,0}//inclined cells addresses
	};
	bool key = 1;
	bool resault = 1;
	char winner;

	//methods:
	void 
	game();

	void 
	print();

	void
	AImove();

	void newmove();

	void  check_winner();
	void call_winner();
 };