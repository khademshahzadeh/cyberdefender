#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class math{
    private:
        vector<int> number;
        vector<int> operatornum;
        vector<char> operators;
        int result=0;
        
        int priorityCheck();

        int calculate();

    public:
        math();

        bool checkAnswer();

        void print();
};
