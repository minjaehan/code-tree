#include <iostream>
#include<cstring>

using namespace std;

int N;

int F_memo[100];


int fibo(int n){
    if(F_memo[n]!=-1){
        return F_memo[n];
    }
    if(n<=2){
        F_memo[n]=1;
    }
    else {
        F_memo[n] = fibo(n-1) + fibo(n-2);
    }
    return F_memo[n];

}


int main() {
    cin >> N;
    memset(F_memo,-1,sizeof(F_memo));

    cout<<fibo(N);

    // Please write your code here.

    return 0;
}
