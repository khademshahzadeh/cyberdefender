#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;

class Scramble
{
    friend ostream &operator <<(ostream &,Scramble );
private:
    string encodedWord;
    string unscrambleWord;
    string scrambleWord;
    void setEncodedWord(){
        srand(time(0));
        int randWord=rand()%499;
        ifstream wordlist("words.dat",ios::in);
        for (int i = 0; i < randWord; i++)
        {
            wordlist>>encodedWord;
        }
    };
    void encodedToUnscramble(){
        for (int i = 0; i < 5; i++)
        {
            unscrambleWord+=char(int(encodedWord[i])-i);
        }   
    }
    void unscrambleToScramble(){
        scrambleWord=unscrambleWord;
        random_shuffle(scrambleWord.begin(),scrambleWord.end());
    }

public:
    Scramble(){
        setEncodedWord();
        encodedToUnscramble();
        unscrambleToScramble();
    };
};
ostream &operator <<(ostream &out,Scramble in){
    out<<in.scrambleWord;
    return out;
}

int main(){
    Scramble test;
    cout<<test;
    return 0;
}