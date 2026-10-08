#include <iostream>
#include<cstring>

using namespace std;

int n;
int memo[1001];
//1일때 1
//2일때 3
//3일때 5

// int square(int n){
//     if(memo[n]!=-1){
//         return memo[n];
//     }
//     if(n==1){
//         memo[n]=1;
//     }
//     else if(n==2){
//         memo[n]=3;
//     }
//     else{
//         memo[n] = (square(n-1)+ 2*square(n-2))%10007;
//     }

//     return memo[n];
// }




int main() {
    cin >> n;
    memset(memo,-1,sizeof(memo));

    memo[1] = 1;
    memo[2] = 3;
    for (int i = 3; i <= n; i++)
        memo[i] = (memo[i - 1] + memo[i - 2] * 2) % 10007;

    // cout<<square(n);
    cout << memo[n];
    return 0;
}
