#include "scramble.h"

void Scramble::setEncodedWord(){
    srand(time(0));
    int randWord=rand()%499;
    ifstream wordlist("Scramble/words.dat",ios::in);
    if (!wordlist){
        cout<<"file";
    }
    for (int i = 0; i < randWord; i++)
    {
        wordlist>>encodedWord;
    }
};
void Scramble::encodedToUnscramble(){
    for (int i = 0; i < 5; i++)
    {
        unscrambleWord+=char(int(encodedWord[i])-i);
    }   
}
void Scramble::unscrambleToScramble(){
    scrambleWord=unscrambleWord;
    random_shuffle(scrambleWord.begin(),scrambleWord.end());
}
Scramble::Scramble(){
    setEncodedWord();
    encodedToUnscramble();
    unscrambleToScramble();
};
bool Scramble::checkAnswer(){
    string answer;
    cin>>answer;
    if (answer==unscrambleWord){
        cout<<"Your answer was correct. Let's go for the next round!"<<endl;
        return true;
    }
    else{
        cout<<"Wrong!"<<endl<<"You can do better dude!"<<endl<<"Try again but you lost one of your chances!"<<endl;
        return false;
    }
}

ostream &operator <<(ostream &out,Scramble in){
    out<<in.scrambleWord<<endl;
    return out;
}
