#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int x1[15], x2[15];

vector<pair<int,int>> selected;

int answer;

bool canSelect(int idx){
    int start = x1[idx];
    int end = x2[idx];

    for(auto s : selected){
        if(end < s.first || s.second < start){ 
            continue;
        }
        return false;
    }

    return true;
}

void dfs(int idx){
    if(idx == n){
        answer = max(answer, (int)selected.size());
        return;
    }

    dfs(idx+1); // 안고르고 그냥 패스. 

    if(canSelect(idx)){
        selected.push_back({x1[idx],x2[idx]});
        dfs(idx+1);
        selected.pop_back();
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    dfs(0);

    cout<<answer;
    return 0;
}

//각 선분을 고른다, 고르지 않는다 이 두가지로 나누기. 
// 백트래킹으로. 
