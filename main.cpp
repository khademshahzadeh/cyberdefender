#include "Math/math.h"
#include "guessing game/mysterynumber.h"
#include "Player and timer/player.h"
#include "Player and timer/timer.h"
#include "Scramble/scramble.h"
#include "x_o/x_oClass.h"
//g++ main.cpp Math\math.cpp "guessing game\mysterynumber.cpp" "Player and timer\player.cpp" "Player and timer\timer.cpp" Scramble\Scramble.cpp x_o\x_oClass.cpp
player test;

void chooseGame(){
    srand(time(0));
    int gameNumber=rand()%5;
    switch (gameNumber)
    {
    case 0:{
        cout<<"math";
        math math;
        cout<<math;
        if(math.checkAnswer()){
            test.win();
        }
        else{
            test.lose();
        }
        chooseGame();
        break;
    }
    case 1:{
        cout<<"mystry";
        Mysterynumber mysterynumber;
        if (mysterynumber.game()){
            test.win();
        }
        else{
            test.lose();
        }
        chooseGame();
    }
    case 2:{
        cout<<"scramble";
        Scramble scramble;
        cout<<scramble;
        if(scramble.checkAnswer()){
            test.win();
        }
        else{
            test.lose();
        }
    }
    case 3:{
        cout<<"xo";
        x_o XO;
        XO.game();
        if (XO.resault){
            test.win();
        }
        else {
            test.lose();
        }
        chooseGame();
    }
    case 4:{
        cout<<"hichi";
        chooseGame();
        break;
    }
    default:
        break;
    }
}
int main(){
    cout<<"Hello!\n * You are hacked :)\n * We have your information\n * either play this game and win it or your information will be spread all over the internet! :)\n * You have just 5 minute to finish at least 3 games...\n * starting from now!"<<endl;
    //time
    chooseGame();
    return 0;
}