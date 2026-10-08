#include <iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>


using namespace std;

int n, k;
int grid[101][101];
int rotten[101][101];
bool visited[101][101];
vector<pair<int,int>> rotplace;

bool inRange(int x, int y){
    return x>0&&x<=n&&y>0&&y<=n;
}

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void bfs(){
    queue<pair<int,int>> q;
    for(int i=0;i<rotplace.size();i++){
        auto [r,c] = rotplace[i];
        visited[r][c]==1;
        q.push({r,c});
    }
    while(!q.empty()){
        auto[x,y] = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(inRange(nx,ny)&&!visited[nx][ny]&&grid[nx][ny]==1){
                q.push({nx,ny});
                visited[nx][ny]=true;
                rotten[nx][ny] =rotten[x][y]+1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(grid[i][j]==1&&rotten[i][j]==0){ //귤은 귤인데 상하지 않은 귤
                rotten[i][j]=-2;
            }
        }
    }
}


int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
            if(grid[i][j]==0){
                rotten[i][j]=-1;
            }
            if(grid[i][j]==2){
                rotplace.push_back({i,j});
            }
        }
    }
    bfs();

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<rotten[i][j]<<" ";
        }
        cout<<"\n";
    }

    // Please write your code here.


    return 0;
}
