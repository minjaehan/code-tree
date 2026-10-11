#include <iostream>
#include<algorithm>


using namespace std;

int n;
int arr[1000];
int DP[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i=0;i<n;i++){
        DP[i]=-1;
    }
    DP[0] = 0;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(DP[j]==-1)continue;

            if(j+arr[j]>=i) DP[i] = max(DP[j]+1,DP[i]);
        }
    }

    int ans=-1;

    for(int i=0;i<n;i++){
        ans = max(ans,DP[i]);
    }

    cout<<ans;



    return 0;
}
