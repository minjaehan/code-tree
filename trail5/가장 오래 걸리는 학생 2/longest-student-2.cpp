#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N, M; //모이는 장소는 N임. 1-4 는 각 학생들. M은 간선 개수. 

int d[1000005];
vector<pair<int,int>> adj[1000005];
const int INF = 1e9+10;



int main() {
    cin >> N >> M;

    fill(d,d+N+1,INF);

    for(int i=0;i<M;i++){
        int u,v,w; // u->v 로가는 간선의 가중치 w
        cin>>u>>v>>w;
        adj[v].push_back({w,u});
    }
    const int st = N;

    d[st] = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    //pq에는 거리와 그 정점이 들어감. 

    pq.push({d[st],st});

    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(d[cur.second]!=cur.first)continue;
        for(auto nxt:adj[cur.second]){
            if(d[nxt.second]<=d[cur.second]+nxt.first)continue;
            d[nxt.second]=d[cur.second]+nxt.first;
            pq.push({d[nxt.second],nxt.second});
        }
    }

    int answer = 0;
    for(int i=1;i<N;i++){
        answer =max(answer,d[i]);
    }

    cout<<answer;


    // Please write your code here.

    return 0;
}
