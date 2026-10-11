#include <iostream>
#include<algorithm>

using namespace std;

int n, m;
int grid[50][50];
int DP[50][50];



int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            DP[i][j] = -1;
        }
    }

    DP[0][0] = 1;

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){

            for(int a=0;a<i;a++){
                for(int b=0;b<j;b++){
                    
                    if(DP[a][b]==-1)continue;
                    if(grid[a][b]<grid[i][j])DP[i][j]=max(DP[a][b]+1,DP[i][j]);
                }
            }
        }
    }


    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans,DP[i][j]);
        }
    }

    

   cout<<ans;


    // Please write your code here.

    return 0;
}
