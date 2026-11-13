#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int grid[200][200];



int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }//grid 채움

    int answerA = 0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            int sum = 0;
            for(int k=i;k<=i+1;k++){
                for(int l=j;l<=j+1;l++){
                    sum +=grid[k][l];
                }
            }
            int result = 0;
            for(int k=i;k<=i+1;k++){
                for(int l=j;l<=j+1;l++){
                    result = max(result,sum-grid[k][l]);
                }
            }

            answerA = max(answerA,result);

        }
    }

    int answerB=0;
    for(int i=0;i<n-2;i++){
        for(int j=0;j<m;j++){
            int sum = 0;
            for(int k=i;k<=i+2;k++){
                sum +=grid[k][j];
            }
            answerB = max(answerB,sum);
        }
    }

    int answerC = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m-2;j++){
            int sum = 0;
            for(int k=j;k<=j+2;k++){
                sum +=grid[i][k];
            }
            answerC = max(answerC,sum);
        }
    }

    int Answer = max(answerA,answerB);
    Answer = max(Answer,answerC);

    cout<<Answer;
    

    


    return 0;
}

// 두가지 종류 모양 
// ㄴ, ㄱ, 역ㄴ, 역ㄱ, ㅡ, ㅣ  -> 2x2 를 먼저 해서 하나씩 빼보는 방법이 있음. 
// 이 6개임. 
// 6가지를 어떻게 셀까 
