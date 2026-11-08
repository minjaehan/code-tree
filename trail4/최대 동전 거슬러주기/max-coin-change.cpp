#include <iostream>
#include<climits>
#include<algorithm>

using namespace std;

int N, M;
int coin[100]; // 동전 종류를 저장하는 배열
int dp[10001];// dp[i] = 금액이 i일때 최대 동전 개수

int main() {
    cin >> N >> M; // M을 거슬러줘야함. 
    for (int i = 0; i < N; i++) {
        cin >> coin[i]; // 동전종류 넣기
    }


    for(int i=1;i<=M;i++){
        dp[i] = INT_MIN;
    }
    dp[0] = 0;

    for(int i=1;i<=M;i++){ // i는 거슬러줄 값
        for(int j=0;j<N;j++){ // j는 동전 종류  3 4 5

            if(i>=coin[j]){
                if(dp[i-coin[j]]==INT_MIN)continue;

                dp[i] = max(dp[i],dp[i-coin[j]]+1);
            }
        }
    }

    int ans = dp[M];

    if(ans==INT_MIN){
        cout<<"-1";
    }
    else cout<<ans;




    return 0;
}
