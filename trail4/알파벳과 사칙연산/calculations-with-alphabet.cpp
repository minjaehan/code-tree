#include <iostream>
#include<set>
#include<climits>


using namespace std;

string exp;

int value[6];

int answer = INT_MIN;


int  calculate(){

    int result = value[exp[0]-'a'];
    for(int i=1;i<exp.size()-1;i+=2){
        char option = exp[i];
        int num = value[exp[i+1]-'a'];

        if(option =='*') result *=num;
        else if(option == '+')result +=num;
        else if(option =='-')result -=num;
    }

    return result;
}

void dfs(int idx){
    if(idx == 6){
        answer = max(answer,calculate());
        return;
    }

    for(int num = 1; num<=4;num++){
        value[idx] = num;
        dfs(idx+1);
    }

}



int main() {
    cin >> exp;


    dfs(0);

    cout<<answer;

    




    return 0;
}

//각 알파벳에 1~4 숫자를 넣어서 결과를 최대로 해보자. 

// - * + 이 아니면   1 or 4를 집어넣는다. 

