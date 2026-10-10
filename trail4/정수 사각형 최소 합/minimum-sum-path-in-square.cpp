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

    DP[0][n-1]= grid[0][n-1];
    for(int i=n-2;i>=0;i--){
        DP[0][i] = DP[0][i+1] + grid[0][i];
    }
    for(int j=1;j<n;j++){
        DP[j][n-1]=DP[j-1][n-1]+grid[j][n-1];
    }


    for(int i=1;i<n;i++){
        for(int j=n-2;j>=0;j--){
            DP[i][j] = min(DP[i-1][j]+grid[i][j],DP[i][j+1]+grid[i][j]);
        }
    }

    cout<<DP[n-1][0];


    return 0;
}
