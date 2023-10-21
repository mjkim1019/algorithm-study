#include <iostream>
#include <algorithm>
using namespace std;

string board[51];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int answer = 0;

    int N,M;
    cin >> N >> M;
    for (int i=0; i<N; i++)
        cin >> board[i];
    

    int K;
    cin >> K;

    for (int i=0; i<N; i++){
        int cnt = 0;
        for (int j=0; j<M; j++) {
            if (board[i][j] == '0') cnt++;
        }
        if (cnt > K || cnt %2 != K %2) continue;

        int res = 0;
        for (int k=i; k<N; k++){
            if (board[i] == board[k]) res++;
        }
        answer = max(answer, res);
    }
    cout << answer;

    return 0;
}