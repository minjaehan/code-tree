#include <iostream>
#include<algorithm>

using namespace std;

int N;
int s[1000], e[1000], p[1000];
int dp[1000]; //-> 일 i를 마지막으로 선택했을 때, 총 얻은 금액. 



int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s[i] >> e[i] >> p[i];
    }

    int ans = 0;
    for(int i=0;i<N;i++){
        dp[i] = p[i];
        for(int j=0;j<i;j++){
            if(e[j]<s[i]){
                dp[i] =max(dp[j]+p[i],dp[i]);
            }
           
        }
        ans = max(ans,dp[i]);

    }

    cout<<ans;

    return 0;
}
