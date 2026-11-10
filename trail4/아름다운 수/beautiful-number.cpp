#include <iostream>

using namespace std;

int n; // n자리의 아름다운 수 
int ans;

void choose(int cnt){
    if(cnt==n){ans++; return;}
    if(cnt>n)return;

    for(int i=1;i<=4;i++){
        choose(cnt+i);
    }
}


int main() {
    cin >> n;

    choose(0);

    cout<<ans;



    return 0;
}
