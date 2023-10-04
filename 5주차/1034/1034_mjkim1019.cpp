#include <iostream>
using namespace std;

char board[51][51];
int N, M;
int K;
int answer;

int count(){
    int res = 0;
    for (int i=0; i<N; i++){
        bool is_valid = true;
        for (int j=0; j<M; j++){
            if (board[i][j] == '0') {
                is_valid = false; break;
            }
        }
        if (is_valid) res++;
    }
    return res;
}

void turn(int k){
    for (int i=0; i<N; i++){
        if (board[i][k] == '0') board[i][k] = '1';
        else board[i][k] = '0';
    }
}

void dfs(int L){
    if (L == K){
        answer = max(answer, count());
        return;
    }

    for (int j=0; j<M; j++){
        turn(j);
        dfs(L+1);
        turn(j);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> N >> M;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            cin >> board[i][j];

    cin >> K;
    dfs(0);
    cout << answer;

    return 0;
}