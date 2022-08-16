#include<bits/stdc++.h>
using namespace std;
 char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
 char turn = 'X';
 int row;
 int column;
 bool draw = false;
void display_board(){
	system("cls");
	cout<<"     |     |     "<<endl;
    cout<<"  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]  <<endl;       
	cout<<"_____|_____|_____"<<endl;
	cout<<"     |     |     "<<endl;
    cout<<"  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]  <<endl;       
	cout<<"_____|_____|_____"<<endl;
	cout<<"     |     |     "<<endl;
    cout<<"  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]  <<endl;
	cout<<"     |     |     "<<endl;
    cout<<endl;
    cout<<endl;
}
void player_turn(){
    int choice;
    if(turn=='X'){
	cout<<"PLAYER 1 TURN : X"<<endl;
    }
    else if(turn=='O'){
    cout<<"PLAYER 2 TURN : O"<<endl;	
    }  
	cin>>choice;
	 
	switch(choice){
		case 1 : row = 0 ;column = 0;break;
		case 2 : row = 0 ;column = 1;break;
		case 3 : row = 0 ;column = 2;break;
	    case 4 : row = 1 ;column = 0;break;
		case 5 : row = 1 ;column = 1;break;
		case 6 : row = 1 ;column = 2;break;
		case 7 : row = 2 ;column = 0;break;
		case 8 : row = 2 ;column = 1;break;
		case 9 : row = 2 ;column = 2;break;
		default:cout<<"Invalid Number"<<endl;
		break;	
	} 

	if(turn=='X' && board[row][column]!='X' && board[row][column]!='O'){
		board[row][column] = 'X';
		turn = 'O';
   	}
    
    else if(turn=='O' && board[row][column]!='X' && board[row][column]!='O'){
		board[row][column] = 'O';
		turn = 'X';
	}
	else {
		cout<<"Box already filled"<<endl;
		cout<<"Please try again"<<endl;
		player_turn();
	}
	 display_board();
}

bool game_over(){
	//check win
    for(int i=0;i<3;i++){
    	if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            return false; 
    	}
    }
    //cross win
    if(board[0][0]==board[1][1] && board[0][0]==board[2][2] || board[0][2]==board[1][1] && board[0][2]==board[2][0]){
    	return false;
    }

    //if box not filled
    for(int i=0;i<3;i++){
    	for(int j=0;j<3;j++){
             if(board[i][j] !='X' && board[i][j]!='O'){
             	return true;
             }
    	}
    }
    //draw
    draw = true;
    return false;
}


int main (){
	cout<<endl;
    
	cout<<"     WELCOME    "<<endl;
	cout<<"       TO       "<<endl;
	cout<<"   TIC TAC TOE  "<<endl;
	cout<<"      GAME      "<<endl;
    cout<<endl<<endl;
    cout<<"PLAYER 1 : X "<<endl;
	cout<<"PLAYER 2 : O "<<endl;
    
    cout<<endl<<endl;


    cout<<"     |     |     "<<endl;
    cout<<"  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]  <<endl;       
	cout<<"_____|_____|_____"<<endl;
	cout<<"     |     |     "<<endl;
    cout<<"  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]  <<endl;       
	cout<<"_____|_____|_____"<<endl;
	cout<<"     |     |     "<<endl;
    cout<<"  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]  <<endl;
	cout<<"     |     |     "<<endl;
    cout<<endl;
    cout<<endl;



    
    while(game_over()){
    player_turn();
    game_over();	
	}

	if(turn=='X' && draw==false){
		cout<<"Player 2 : O -> WINS !! Congratulations"<<endl;
	}
	else if(turn=='O' && draw==false){
		cout<<"Player 1 : X -> WINS !! Congratulations"<<endl;
	}
	else {
        cout<<"Game Draw !!"<<endl;
	}
}	