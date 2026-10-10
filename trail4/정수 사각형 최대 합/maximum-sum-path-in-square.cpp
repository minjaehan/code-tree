#include <iostream>
#include<algorithm>
using namespace std;

int n;
int grid[100][100];
int DP[101][101];

//초기조건 1. 밑으로만 가는 경우
//초기조건 2. 오른쪽으로만 갔던 경우.

void initialize(){
    DP[0][0] = grid[0][0]; //0,0

    for(int i = 1; i < n; i++){
        DP[i][0] = DP[i-1][0] + grid[i][0]; //아래로
        DP[0][i] = DP[0][i-1] + grid[0][i]; // 오른쪽으로
    }
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    initialize();

    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            DP[i][j] = max(DP[i][j-1]+grid[i][j],DP[i-1][j]+grid[i][j]);
        }
    }

    cout<<DP[n-1][n-1];


    // Please write your code here.

    return 0;
}
