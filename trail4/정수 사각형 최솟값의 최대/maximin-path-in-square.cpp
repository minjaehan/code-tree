#include <iostream>
#include<algorithm>

using namespace std;

int n;
int grid[100][100];
int DP[100][100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    DP[0][0] = grid[0][0];
    for(int i=1;i<n;i++){
        DP[0][i] = min(DP[0][i-1],grid[0][i]);
        DP[i][0] = min(DP[i-1][0],grid[i][0]);
    } //초기 세팅

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(grid[i][j]>max(DP[i-1][j],DP[i][j-1])){
                
                DP[i][j] =max(DP[i-1][j],DP[i][j-1]);
            }
            else DP[i][j]=grid[i][j];
        }
    }

    cout<<DP[n-1][n-1];




    // Please write your code here.

    return 0;
}
