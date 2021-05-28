#include "math.h"

int math::priorityCheck(){
    for (int i=0;i<operatornum.size();i++){
        if(operatornum[i]==2){
            number[i]=number[i]*number[i+1];
            operatornum.erase(operatornum.begin()+i);
            operators.erase(operators.begin()+i);
            number.erase(number.begin()+i+1);
            i--;
        }
    }
}

int math::calculate(){
    priorityCheck();
    result+=number[0];
    for (int i=0; i<operatornum.size(); i++){
        if (operatornum[i]==0){
            result+=number[i+1];        
        }
        else{
            result-=number[i+1];        
        }
    }
}

math::math(){
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

bool math::checkAnswer(){
    calculate();
    int answer;
    cin>>answer;
    if (answer==result){
        cout<<"Your answer was correct. Let's go for the next round!"<<endl;
        return true;
    }
    else{
        cout<<"Wrong!"<<endl<<"You can do better dude!"<<endl<<"Try again but you lost one of your chances!"<<endl;
        return false;
    }
}

ostream &operator <<(ostream &out,math in){
    for (int i=0;i<in.operators.size();i++){
        out<<in.number[i]<<in.operators[i];
    }
    out<<in.number[8]<<"= ?"<<endl;
    return out;
}