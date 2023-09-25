#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second
#define INF 0x7f7f7f7f

int board[1001][1001];
int dist[1001][1001];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int M, N;

bool OOB(int x, int y){
    if (x < 0 || x >= M || y < 0 || y >= N) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    queue<pair<int, int>> Q;
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            cin >> board[i][j];
            if (board[i][j] == 1) {
                Q.push({i, j});
            }
        }
    }

    while (!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (OOB(nx, ny)) continue;
            if (board[nx][ny] != 0) continue;
            board[nx][ny] = board[cur.X][cur.Y] +1;
            Q.push({nx, ny});
        }
    }
    
    int answer = -1;
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            if (board[i][j] == 0) {
                cout << -1; return 0;
            }
            answer = max(answer, board[i][j]);
        }
    }
    cout << answer-1;

    return 0;
}