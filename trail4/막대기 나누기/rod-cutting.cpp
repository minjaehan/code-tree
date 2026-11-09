#include <iostream>
#include<climits>
#include<algorithm>

using namespace std;

int n;
int profit[101];
int dp[101];  // 막대 길이가 i일때 최대 수익값 dp[i];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> profit[i]; // 이익. 
    }

    for(int i=1;i<=n;i++){
        dp[i] = INT_MIN;
    }
    dp[0] = 0;

    for(int i=1;i<=n;i++){
        dp[i] = profit[i];

        for(int k=1;k<i;k++){
            dp[i] = max(dp[i],dp[i-k]+profit[k]);
        }
    }

    cout<<dp[n];

    return 0;
}
