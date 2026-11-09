#include <iostream>
#include<climits>
#include<algorithm>

using namespace std;

int N, M;
int w[100], v[100];
int dp[10001]; // i가 무게일 때 총 밸류 dp[i];


int main() {
    cin >> N >> M; // 종류 N,  총 무게 M

    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    for(int i=0;i<=M;i++){
        dp[i]= 0;
    }

    for(int i=0;i<N;i++){ // 보석 정보는 맨 바깥
        for(int s=w[i];s<=M;s++){


            dp[s] = max(dp[s],dp[s-w[i]]+v[i]);
        }
    }

    cout<<dp[M];


    

    // Please write your code here.

    return 0;
}
