#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define X first
#define Y second

int N, M;
char board[25][25];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool OOB(int x, int y){
    if (x < 0 || x >= N || y < 0 || y >= M) return true;
    return false;
}

int answer = 11;

void dfs(int L, int x1, int y1, int x2, int y2){
    if (L >= 10 || answer < L) return;

    for (int dir=0; dir<4; dir++){
        int nx1 = x1 + dx[dir];
        int ny1 = y1 + dy[dir];
        int nx2 = x2 + dx[dir];
        int ny2 = y2 + dy[dir];

        // 벽에 막히는 거 생각해야함
        if (board[nx1][ny1] == '#') {
            nx1 = x1; ny1 = y1;
            if (nx1 == nx2 && ny1 == ny2) continue; // 현재위치
        }
        if (board[nx2][ny2] == '#'){
            nx2 = x2; ny2 = y2;
            if (nx1 == nx2 && ny1 == ny2) continue;
        }

        bool valid1 = OOB(nx1, ny1);
        bool valid2 = OOB(nx2, ny2);
        if (valid1 && valid2) continue;
        else if (valid1 && !valid2) {
            answer = min(answer, L + 1);
            break;
        }
        else if (!valid1 && valid2) {
            answer = min(answer, L + 1);
            break;
        }
        else {
            dfs(L+1, nx1, ny1, nx2, ny2);
        }

    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    vector<pair<int, int>> coins;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> board[i][j];
            if (board[i][j] == 'o') coins.push_back({i, j});
        }
    }

    dfs(0, coins[0].X, coins[0].Y, coins[1].X, coins[1].Y);

    if (answer == 11) cout << "-1";
    else cout << answer;

    return 0;
}