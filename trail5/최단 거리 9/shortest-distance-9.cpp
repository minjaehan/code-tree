#include <iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
int A,B;
vector<pair<int,int>> adj[1005];
int d[10005];
int path[1005];
int INF = 1e9+10;


int main() {
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }

    cin>>A>>B;
    int st = A; //시작점은 A

    fill(d,d+n+1,INF); 
     d[A] = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    pq.push({d[st],st});

    path[st]=0;

    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(d[cur.second]!=cur.first)continue;
        for(auto nxt : adj[cur.second]){
            if(d[nxt.second]<=d[cur.second]+nxt.first)continue;
            d[nxt.second]=d[cur.second]+nxt.first;
            path[nxt.second]=cur.second;
            pq.push({d[nxt.second],nxt.second});
        }
    }


    //이제 최단거리를 구하고 그 path를 구해야 함.  1, 5

    cout<<d[B]<<"\n";
    
    int last = B;
    vector<int> answer;
    while(last!=0){
        answer.push_back(last); //일단 5 들어감. 
        last = path[last]; // 
    }

    for(int i=answer.size()-1;i>=0;i--){
        cout<<answer[i]<<" ";
    }


    





    // Please write your code here.

    return 0;
}
