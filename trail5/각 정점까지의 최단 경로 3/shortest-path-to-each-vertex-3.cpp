#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, m;

vector<pair<int,int>> adj[105];
int d[105];
int INF = 1e9+10;


int main() {
    cin >> n >> m; // n개의 정점, m개의 간선양끝정점 and 가중치 

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({w,v});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    //pq에 들어가는거는  (거리, 정점)임. 
    const int st = 1;

    fill(d,d+n+1,INF);

    d[st]=0;

    pq.push({d[st],st});

    

    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(d[cur.second]!=cur.first)continue;   //기존꺼랑 다르면 패스. 
        for(auto nxt : adj[cur.second]){
            if(d[nxt.second]<=d[cur.second]+nxt.first)continue;
            d[nxt.second]=d[cur.second]+nxt.first;
            pq.push({d[nxt.second],nxt.second});
        }
    }

    for(int i=2;i<=n;i++){
        if(d[i]==INF)cout<<"-1\n";
        else cout<<d[i]<<"\n";
    }





    

    // Please write your code here.

    return 0;
}
