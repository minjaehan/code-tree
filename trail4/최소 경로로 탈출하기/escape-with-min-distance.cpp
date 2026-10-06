#include <iostream>
#include<queue>
#include<vector>


using namespace std;

int n, m;
int a[101][101];
bool visited[101][101];
int step[101][101];

int dx[4] ={-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool inRange(int x, int y){
    return x>0&& x<=n&& y>0&&y<=m;
}

void bfs(int x, int y){
    visited[x][y]=true;
    queue<pair<int,int>> q;
    q.push({x,y});

while(!q.empty()){
    int cx = q.front().first;
    int cy = q.front().second;
    q.pop();
    for(int i=0;i<4;i++){
        int nx = cx +dx[i];
        int ny = cy +dy[i];
        if(!visited[nx][ny]&& inRange(nx,ny)&&a[nx][ny]==1){
            visited[nx][ny]=true;
            q.push({nx,ny});
            step[nx][ny]=step[cx][cy]+1;

        }

    }
}
    


}


int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    bfs(1,1);

    if(step[n][m]==0){
        cout<<"-1\n";
    }
    else cout<<step[n][m]<<"\n";



    // Please write your code here.

    return 0;
}
