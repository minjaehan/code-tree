#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<int> answer;

void choose(int cnt) {
    if (cnt == N) {
        for (int v : answer) cout << v << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= K; i++) {
        answer.push_back(i);   // i를 고르고
        choose(cnt + 1);       // 다음 자리 채우러 가고
        answer.pop_back();     // 돌아오면 i를 빼서 다음 후보 시도
    }
}

int main() {
    cin >> K >> N;
    choose(0);
    return 0;
}