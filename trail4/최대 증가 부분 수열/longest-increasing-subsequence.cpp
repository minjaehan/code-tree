#include <iostream>
#include<climits>
#include<algorithm>

using namespace std;

int N;
int M[1000];
int DP[1000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }
    for(int i=0;i<N;i++){
        DP[i] = 1;
    }
    DP[0] = 1;

    for(int i=1;i<N;i++){
        for(int j = 0;j<i;j++){
            

            if(M[j]<M[i]) DP[i] = max(DP[i],DP[j]+1);

        }
    }

    int max_num = 0;
    for(int i=0;i<N;i++){
        if(DP[i]>max_num) max_num=DP[i];
    }

    cout<<max_num<<"\n";


    return 0;
}
