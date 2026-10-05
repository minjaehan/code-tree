#include <iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>


using namespace std;

int n, k, m;
int grid[101][101];
bool visited[101][101];
int answer=0;

vector<pair<int,int>> stones, starts, picked;

bool inRange(int x , int y){
    return x>0&&x<=n&&y>0&&y<=n;
}

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};


//백트래킹으로 치울 돌 선택
void select(int cnt){
    if(cnt==k)return;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){

        }
    }


}

int move(){
    memset(visited, false, sizeof(visited)); // 방문 초기화
    queue<pair<int,int>> q;
    for(auto[r,c]:starts){
        if(!visited[r][c]){
            visited[r][c]=true;
            q.push({r,c});
        }
    }
    int cnt = q.size();
    while(!q.empty()){
        auto[x,y]=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(inRange(nx,ny)&&!visited[nx][ny]&&!grid[nx][ny]){
                visited[nx][ny]=true;
                q.push({nx,ny});
                cnt++;
            }
        }
    }
    return cnt;

}

void choose(int start){
    if(picked.size()==m){
        for(auto [r,c]:picked){
            grid[r][c]=0;
        }
        answer=max(answer,move());
        for(auto [r,c]:picked){
            grid[r][c]=1;
        }
    }

    for(int i=start; i<stones.size();i++){
        picked.push_back(stones[i]);
        choose(i+1);
        picked.pop_back();
    }
}


int main() {
    cin >> n >> k >> m; 

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> grid[i][j]; // grid 채우기.
            if(grid[i][j]==1) stones.push_back({i,j}); //돌인 그리드 저장
        }    
    }

    for(int i=0;i<k;i++){
        int r,c;
        cin>>r>>c;
        starts.push_back({r,c});
    }

    choose(0);
    cout<<answer<<"\n";


    // Please write your code here.

    return 0;
}
