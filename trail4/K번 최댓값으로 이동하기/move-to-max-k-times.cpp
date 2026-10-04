#include <iostream>
#include<queue>
#include<cstring>
using namespace std;

int n, k;
int grid[101][101];
bool visited[101][101];


int r, c;
int now_val = 0;
//매 회차 저장해야 하는것 : 최대값이랑 최대값의 위치. 
int max_num=0;

bool inRange(int x, int y){
    return x>=1&&x<=n&& y>=1&&y<=n;
}

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool bfs(){
    memset(visited,false,sizeof(visited));
    int target = grid[r][c];
    queue<pair<int,int>> q;
    visited[r][c] =true;
    q.push({r,c});
    int bestVal = -1, bestR = -1, bestC = -1;
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(!inRange(nx,ny)||visited[nx][ny]) continue;
            if(grid[nx][ny]>=target) continue;
            visited[nx][ny]=true;
            q.push({nx,ny});
            int v = grid[nx][ny];
            if (v > bestVal ||
                (v == bestVal && (nx < bestR || (nx == bestR && ny < bestC)))) {
                bestVal = v; bestR = nx; bestC = ny;
            }

        }
    }
    if(bestVal == -1) return false;
    r=bestR; c = bestC;
    return true;

}

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;
    now_val = grid[r][c];

    for(int i=0;i<k;i++){
        if(!bfs()) break;
        
    }

    cout<<r<<" "<<c<<"\n";

    // Please write your code here.

    return 0;
}
