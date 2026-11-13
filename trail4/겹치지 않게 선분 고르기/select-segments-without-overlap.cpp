#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int,int>> segment;
vector<pair<int,int>> selected;

int answer;

bool canSelect(int idx){
    int first = segment[idx].first;
    int last = segment[idx].second;
    for(auto a : selected){
        if(a.first>last || a.second<first){
            continue;
        }
        return false;
    }
    return true;
}

void dfs(int idx){
    if(idx==n){
        answer = max(answer,(int)selected.size());
        return;
    }

    dfs(idx+1);

    if(canSelect(idx)){
        selected.push_back(segment[idx]);
        dfs(idx+1);
        selected.pop_back();
    }
}


int main() {

    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        segment.push_back({a, b});
    }

    dfs(0);
    cout<<answer;




}

//각 선분을 고른다, 고르지 않는다 이 두가지로 나누기. 
// 백트래킹으로. 
