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
        vector<char> operators;
        int result;
    public:
        int calculate(){
            for (int i=0;i<operatornum.size();i++){
                if(operatornum[i]==2){
                    if(i!=operatornum.size()-1){
                        number[i]=number[i]*number[i+1];
                        operatornum.erase(operatornum.begin()+i);
                        operators.erase(operators.begin()+i);
                        number.erase(number.begin()+i+1);
                        i--;
                    }
                    else{
                        cout<<"here!"<<endl;
                        number.push_back(number[i]*number[i-1]);
                        operatornum.erase(operatornum.begin()+i);
                        operators.erase(operators.begin()+i);
                        number.erase(number.begin()+i);
                        number.erase(number.begin()+i+1);
                    }
                }
            }
            print();
        }
        math(){
            srand(time(0));
            for (int i=0; i<9;i++){
                number.push_back(rand()%5+i);
            }
            for (int i=0; i<8;i++){
                operatornum.push_back(rand()%3);
                switch (operatornum[i])
                {
                case 0:{
                    operators.push_back('+');
                    break;
                }
                case 1:{
                    operators.push_back('-');
                    break;
                }
                case 2:{
                    operators.push_back('*');
                    break;
                }
                default:
                    break;
                }
            }
            if (operatornum[operatornum.size()-1]==2){
                operatornum[operatornum.size()-1]=1;
                operators[operatornum.size()-1]='-';
            }
        };
        print(){
            for (int i=0;i<operators.size();i++){
                cout<<number[i]<<operators[i];
            }
            cout<<number[8]<<"= ?"<<endl;
        }
};

int main(){
    math test;
    test.print();
    test.calculate();
    // system("PAUSE");
    return 1;
}