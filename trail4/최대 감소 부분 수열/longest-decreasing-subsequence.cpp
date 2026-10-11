#include <iostream>
#include<algorithm>

using namespace std;

const int MAX_N = 1000;

int N;
int M[MAX_N];
int DP[MAX_N];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }

    for(int i=0;i<N;i++){
        DP[i] =1;
    }
    for(int i=1;i<N;i++){
        for(int j=0;j<i;j++){
            if(M[i]<M[j]){
                DP[i] = max(DP[i],DP[j]+1);
            }
        }
    }

    int ans=0;
    for(int i=0;i<N;i++){
        ans = max(ans,DP[i]);
    }

    cout<<ans;


    return 0;
}
