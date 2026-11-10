#include <iostream>
#include<vector>
using namespace std;

int K, N;

vector<int> answer;
void choose(int cnt)
{   
    if(cnt==N){
        for(int v : answer){
            cout<<v<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=1;i<=K;i++){
        answer.push_back(i);
        choose(cnt+1);
        answer.pop_back();
    }
}

int main() {
    cin >> K >> N; //K 까지의 정수중에서 중복 포함에서 N개 고르기

    choose(0);




    return 0;
}
