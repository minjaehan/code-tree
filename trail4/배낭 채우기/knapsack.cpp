#include <iostream>
#include<climits>
#include<algorithm>

using namespace std;

int N, M; //보석 N개, 배낭 무게 합은 M 
int w[100], v[100];

int dp[10001];  // 베낭 무게 i 일때 최대 밸류 dp[i]

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    for(int i=0;i<=M;i++){
        dp[i] = INT_MIN;
    }

    dp[0] = 0;

    for(int j=0;j<N;j++){
        for(int s=M;s>=w[j];s--){
            if(dp[s-w[j]]==INT_MIN)continue;

            dp[s] = max(dp[s-w[j]]+v[j],dp[s]);
        }
    }

    int max_num = 0;

    for(int i=1;i<=M;i++){
        max_num = max(max_num,dp[i]);
    }

    cout<<max_num;
    
    


    return 0;
}


//무게 합 M 안넘으면서 최대 밸류 V 구하기. 