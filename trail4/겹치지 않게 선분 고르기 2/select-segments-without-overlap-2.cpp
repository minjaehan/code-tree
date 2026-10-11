#include <iostream>
#include<algorithm>

using namespace std;

int n;
pair<int,int> seg[1000];
int dp[1000];



int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin>>seg[i].first>>seg[i].second;
    }

    sort(seg,seg+n);
    int ans = 0;

    for(int i=0;i<n;i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            if(seg[j].second<seg[i].first){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        ans = max(ans,dp[i]);
    }

    cout<<ans;

    return 0;
}
