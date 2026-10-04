#include <iostream>
#include<vector>
#include<queue>

using namespace std;

int n, k;
int grid[101][101];
int visited[101][101];
vector<pair<int,int>> rc; // r,c  : k의 좌표
queue<pair<int,int>> q;
int cnt;

bool inRange(int x, int y){
    return x>0&&x<=n&&y>0&&y<=n;
}

int dx[4]= {-1,1,0,0};
int dy[4]={0,0,-1,1};

void bfs(int x, int y){
    q.push({x,y}); // q에 넣고 방문처리
    if(visited[x][y]!=1){
        visited[x][y]=1; 
        cnt++;
    }
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(inRange(nx,ny)&&!grid[nx][ny]&&!visited[nx][ny]){
                q.push({nx,ny});
                visited[nx][ny]=1;
                cnt++;
            }
        }
    }
}


int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++){
        int a,b;
        cin>>a>>b;
        rc.push_back({a,b});
    }

    for(int i=0;i<k;i++){
        bfs(rc[i].first,rc[i].second);
    }    

    cout<<cnt;

    // Please write your code here.

    return 0;
}
