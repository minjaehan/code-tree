#include <iostream>
#include<queue>
#include<vector>
#include<cstring>



using namespace std;

int n, h, m;
int grid[101][101];
int visited[101][101];
int answer[101][101];


vector<pair<int,int>> human;



bool inRange(int x, int y){
    return x>0&&x<=n&&y>0&&y<=n;
}

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};


int bfs(int x , int y){
    memset(visited,0,sizeof(visited));
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        auto [r,c] = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = r+dx[i];
            int ny = c+dy[i];
            if(inRange(nx,ny)&&!visited[nx][ny]&&grid[nx][ny]!=1){
                q.push({nx,ny});
                visited[nx][ny]=visited[r][c]+1;
                 if(grid[nx][ny]==3){
                    return visited[nx][ny];
                }

            }
        }
    }
    return -1;
}


// 0은 빈공간, 1은 벽, 2는 사람, 3은 비 피하는 공간
int main() {
    cin >> n >> h >> m;


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
            if(grid[i][j]==2){
                human.push_back({i,j});
            }
        }
    }

    // 1인 애들에서 시작해서 돌리기. 
    for(int i=0;i<human.size();i++){
        answer[human[i].first][human[i].second]= bfs(human[i].first, human[i].second);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<answer[i][j]<<" ";
        }
        cout<<"\n";
    }


    // Please write your code here.

    return 0;
}
