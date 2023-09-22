// 모든 위치에서 벽 부수는 거 최소가 되도록
// 다익스트라 최소힙
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

char board[105][105];
int d[105][105];

int N, M;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct Pos{
    int x, y;
    int dist;
    Pos(int a, int b, int d){
        x=a; y=b; dist = d;
    }
    bool operator <(const Pos &p) const{
        return dist < p.dist;
    }
};

priority_queue<Pos> pq;

bool OOB(int x, int y){
    if (x<0 || x >= N|| y <0 || y>=M) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;

    for (int i=0; i<N; i++)
        cin >> board[i];
    
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            d[i][j] = INF;

    d[0][0] = 0;
    pq.push(Pos(0, 0, 0));
    while (!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if (d[cur.x][cur.y] != cur.dist) continue;
        //cout << cur.x << ", " << cur.y << " = "<< cur.dist << '\n';

        for (int dir=0; dir<4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (OOB(nx, ny)) continue;

            if (d[nx][ny] > cur.dist + board[nx][ny]-'0'){
                d[nx][ny] = cur.dist + board[nx][ny] -'0';
                pq.push(Pos(nx, ny, d[nx][ny]));
            }
        }
    }

    cout << d[N-1][M-1];

    return 0;
}