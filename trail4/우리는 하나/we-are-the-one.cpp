#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>


using namespace std;

int n, k, u, d;
int grid[10][10];
bool visited[10][10];
vector<pair<int,int>> cities,starts;
int total=0;


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

bool inRange(int x,int y){
    return x>0&&x<=n&&y>0&&y<=n;
}

int bfs(){
    memset(visited,false,sizeof(visited));
    queue<pair<int,int>> q;
    int count=starts.size();
    for(auto[r,c]:starts){
        visited[r][c]=true;
        q.push({r,c});
    }
    while(!q.empty()){
        auto[x,y] = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(inRange(nx,ny)&&!visited[nx][ny]){
                if( abs(grid[x][y]-grid[nx][ny])<=d &&abs(grid[x][y]-grid[nx][ny])>=u){
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                    count++;
                }
            }
        }
    }
    return count;
}

void select(int idx,int cnt){ // 여기서의 동작 : 시작점을 k 개수만큼 고른다.
    if(cnt==k){
       total = max(total,bfs());
       return;
    }
    for(int i=idx;i<cities.size();i++){
        starts.push_back(cities[i]);
        select(i+1, cnt+1);
        starts.pop_back();
    }
}

int main() {
    cin >> n >> k >> u >> d;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
            cities.push_back({i,j});
        }
    }

    select(0,0);

    cout<<total<<"\n";








    // Please write your code here.

    return 0;
}
