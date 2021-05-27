#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
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
public:
    Scramble(){
        setEncodedWord();
        encodedToUnscramble();
    };
};
ostream &operator <<(ostream &out,Scramble in){
    out<<in.unscrambleWord;
    return out;
}

int main(){
    Scramble test;
    cout<<test;
    return 0;
}