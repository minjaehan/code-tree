#include <iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
int grid[500][500];
int DP[500][500];

//정해야할거. 시작점을 어떻게 정할지.
// DP배열 안에 들어갈거. 
// 방문처리를 해야할까?


int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool inRange(int x, int y){
    return x>=0&&x<n&& y>=0&&y<n;
}

int loop(int x, int y){
    if(DP[x][y]!=0)return DP[x][y];

    DP[x][y]=1;

    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(inRange(nx,ny)&&grid[nx][ny]>grid[x][y]){
            DP[x][y]=max(DP[x][y],loop(nx,ny)+1);
           
        }
    }
    return DP[x][y];
}

int main() {

    cin>>n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){ // 시작점 정하고 루프 돌리기
            loop(i,j);
        }
    }

    int max_num = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            max_num = max(max_num,DP[i][j]);
        }
    }

    cout<<max_num;


    return 0;
}
