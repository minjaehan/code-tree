#include <iostream>

using namespace std;

int n, m;
int A[100];
bool dp[10001]; // 합이 i가 될 수 있도록 고를 수 있는가?



int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    dp[0]=true;

    //차례대로 고르는거임. 5개 중에서 몇개 골랐는데 12가 되는거 구하는거. 
    //5개 조합해서 12되는거 고르기. 

    for(int i = 0; i<n;i++){ // 5 2 4 9 1 
        for(int j=m;j>=A[i];j--){
            if( dp[j-A[i]]==true) dp[j]=true;
        }
    }
    
    if(dp[m]==true)cout<<"Yes";
    else cout<<"No";




    return 0;
}
