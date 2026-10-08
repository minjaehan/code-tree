#include <iostream>
#include<cstring>

using namespace std;

int memo[1001];

int stair(int n){
    if(memo[n]!=-1){
        return memo[n];
    }
    if(n==1){
        memo[n]=0;
    }
    else if(n==2||n==3){
        memo[n]=1;
    }
    else{
        memo[n] = (stair(n-2)+stair(n-3)) %10007;
    }
    return memo[n];

}

int n;

int main() {
    cin >> n;
    // Please write your code here.
    memset(memo,-1,sizeof(memo));

    cout<<stair(n)<<"\n";

    return 0;
}