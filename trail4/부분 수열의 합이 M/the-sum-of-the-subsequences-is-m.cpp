#include <iostream>
#include<algorithm>

using namespace std;

int n, m;
int A[100];
int DP[101][10001];
int INF = 1e9;


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    fill(&DP[0][0],&DP[0][0]+101*10001,INF);

    DP[0][0] = 0;

    for(int j=0;j<n;j++){
        for(int i=0;i<=m;i++){
            DP[j+1][i]= DP[j][i];
            if(i>=A[j]){
                DP[j+1][i] = min(DP[j+1][i],DP[j][i-A[j]]+1);
            }
        }
    }

    if(DP[n][m]==1e9)cout<<"-1\n";
    else cout<<DP[n][m];

    // Please write your code here.

    return 0;
}
