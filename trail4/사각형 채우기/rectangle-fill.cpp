#include <iostream>
#include<cstring>
using namespace std;

int n;
// 1일때 1 
// 2일때 2
// 3일때 3
//  
int memo[1001];

int square(int n){
    if(memo[n]!=-1){
        return memo[n];
    }
    if(n<=3){
        memo[n] = n;
    }
    else {
        memo[n] = (square(n-1)+ square(n-2)) %10007;
    }
    return memo[n];
    
}

int main() {
    cin >> n;
    memset(memo,-1,sizeof(memo));

    cout<<square(n)<<"\n";

    // Please write your code here.

    return 0;
}
