#include <iostream>
#include<algorithm>

using namespace std;

int n;
int grid[100][100];
int DP[100][100]; // 해당 좌표까지의 최댓값의.

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    DP[0][0] = grid[0][0];

    for(int i=1;i<n;i++){
        DP[i][0] = max(DP[i-1][0],grid[i][0]);
        DP[0][i] = max(DP[0][i-1],grid[0][i]); //초기 설정. 
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(grid[i][j]>min(DP[i-1][j],DP[i][j-1])){
                DP[i][j] = grid[i][j];
            }
            else DP[i][j] = min(DP[i-1][j],DP[i][j-1]);

        }
    }

    cout<<DP[n-1][n-1];



    return 0;
}
