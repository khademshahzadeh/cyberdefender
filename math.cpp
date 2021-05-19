#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class math{
    private:
        vector<int> number;
        vector<int> operatornum;
        char operators[8];
        int result;
    public:

        math(){
            srand(time(0));
            for (int i=0; i<9;i++){
                number.push_back(rand()%10+i+6);
            }
            for (int i=0; i<8;i++){
                operatornum.push_back(rand()%3);
                switch (operatornum[i])
                {
                case 0:{
                    operators[i]='+';
                    break;
                }
                case 1:{
                    operators[i]='-';
                    break;
                }
                case 2:{
                    operators[i]='*';
                    break;
                }
                default:
                    break;
                }
            }
        };
        print(){
            for (int i=0;i<8;i++){
                cout<<number[i]<<operators[i];
            }
            cout<<number[8]<<"= ?"<<endl;
        }
};

int main(){
    math test;
    test.print();
    system("PAUSE");
    return 1;
}