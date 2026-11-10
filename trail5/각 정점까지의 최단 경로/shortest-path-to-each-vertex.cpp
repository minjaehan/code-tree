#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define X first
#define Y second

int v,e,st;

vector<pair<int,int>>adj[20005];
const int INF = 1e9+10;
int d[20005];

int main(){

    cin>>v>>e>>st;
    fill(d,d+v+1,INF);

    while(e--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});  //u에서 v로 이동할 때 가중치 W임.  무방향 그래프면 양쪽으로 추가함. 
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;  //first에 거리, second에 정점 들어감. 
    d[st] = 0;

    pq.push({0,st});//우선순위큐에 시작점까지의 거리와 그 시작점 즉 0을 넣는다.   0, 1 들어감. 

    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(d[cur.Y]!=cur.X)continue; //이미 더 짧은 경로가 발견된 오래된 원소는 건너뜀. 
        for(auto nxt : adj[cur.Y]){  // 현재 정점과 인접한 애들을 nxt로 하고 순회.  nxt는 pair인데 {가중치, 다음정점}임. 
            if(d[nxt.Y]<=d[cur.Y]+nxt.X)continue; //nxt의 거리가 합한거보다 더 작으면 건너뜀
            d[nxt.Y]= d[cur.Y]+nxt.X;
            pq.push({d[nxt.Y],nxt.Y});
        }
    }

    for(int i=1;i<=v;i++){
        if(d[i]==INF)cout<<"-1\n";
        else cout<<d[i]<<"\n";
    }




}
