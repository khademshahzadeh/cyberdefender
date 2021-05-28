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
    void setEncodedWord();
    void encodedToUnscramble();
    void unscrambleToScramble();
public:
    Scramble();
    bool checkAnswer();
};
ostream &operator <<(ostream &out,Scramble in);
