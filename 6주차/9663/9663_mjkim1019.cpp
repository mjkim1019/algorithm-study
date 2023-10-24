#include <iostream>
using namespace std;

bool row[15];
bool upright[30]; // i + j 같음
bool downright[30]; // i - j 같음
int N;
int answer = 0;

// L번째 행의 퀸 놓는 방법
void func(int L){
    if (L == N) {
        answer++;
        return;
    }

    for (int j=0; j<N; j++){
        if (row[j]) continue; // 되는 열인지 확인
        if (upright[L+j]) continue; 
        if (downright[L-j+N]) continue;

        row[j] = true;
        upright[L+j] = true;
        downright[L-j+N] = true;
        func(L+1);
        row[j] = false;
        upright[L + j] = false;
        downright[L - j + N] = false;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    func(0);
    cout << answer;

    return 0;
}