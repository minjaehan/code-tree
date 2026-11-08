#include <iostream>
#include <algorithm>

using namespace std;

int n;



long long  dp[1001]; 

// dp[1] 은 1의 방법수
// dp[2] 는 2를 만드는 방법 수. 
// dp[3]  은 3을 만드는 방법 수. 



int main() {
    cin >> n;



    dp[0] = 1;

    for(int i=1;i<=n;i++){


        dp[i] += dp[i-1] %10007;

        if(i>=2) dp[i]=(dp[i] + dp[i-2]) %10007;

        if(i>=5) dp[i]= (dp[i]+dp[i-5])%10007;
    }

    cout<<dp[n];







    return 0;
}
