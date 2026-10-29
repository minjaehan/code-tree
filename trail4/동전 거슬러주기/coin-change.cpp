#include <iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<cstring>


using namespace std;

int N, M;
int coin[100];
int DP[10001]; // dp[i] 를 만들기 위한 최소 동전 개수 i
int INF = 1e9;

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }
    fill(DP,DP+M+1,INF);

    DP[0] = 0; //0이 basecase

    for(int i=1;i<=M;i++){
        for(int j=0;j<N;j++){
            if(i>=coin[j]){

                DP[i] = min(DP[i],DP[i-coin[j]]+1);
            }

        }
    }

    if(DP[M] == INF){
        cout<<"-1"<<"\n";
    }
    else cout<<DP[M];

// 1 4 5
    
    


    return 0;
}
