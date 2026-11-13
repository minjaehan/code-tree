#include <iostream>
#include<algorithm>

using namespace std;

int N;
int grid[20][20];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {        // 0 ~ n-1
        for (int j = 0; j < N; j++) {    //0 ~ n-1
            cin >> grid[i][j];
        }
    }

    int answer = 0;

    for(int i=0;i<N-2;i++){
        for(int j=0;j<N-2;j++){ //왼쪽 상단 정의함. 
            int result =0;
            for(int k=i;k<i+3;k++){
                for(int l=j;l<j+3;l++){
                    if(grid[k][l]==1)result++;
                }
            }
            answer = max(answer,result);
        }
    }

    cout<<answer;


    return 0;
}

// 1.3x3 격자 안에 들어갈 칸을 정한다. 
// 2.그 안에 들어가는 동전 개수를 센다
