#include <iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int grid[101][101];
int n;
int r1, c1, r2, c2;

int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {-1,1,2,-2,2,-2,-1,1};

bool inRange(int x, int y){
    return x>0&&x<=n&&y>0&&y<=n;
}


int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    memset(grid,-1,sizeof(grid));
    grid[r1][c1]=0;
    queue<pair<int,int>> q;
    q.push({r1,c1});
        while(!q.empty()){
        auto [r,c] = q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int nx = r+dx[i];
            int ny = c+dy[i];
            if(inRange(nx,ny)&&grid[nx][ny]==-1){
                q.push({nx,ny});
                grid[nx][ny]= grid[r][c]+1;
            }
        }
    }

    cout<<grid[r2][c2]<<"\n";





    

    // Please write your code here.

    return 0;
}
