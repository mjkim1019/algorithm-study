#include <iostream>
#include <algorithm>
using namespace std;
#define X first 
#define Y second
#define INF 0x7f7f7f7f
#define ll long long

int N;
pair<int, int> pos[100005][5];
ll d[100005][5];

int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

bool OOB(int x, int y){
    if (x < 1 || x > 100000 || y <1 || y > 100000) return true;
    return false;
}

ll dist(int x, int y, int a, int b) {
    return abs(x-a) + abs(y-b);
}

ll move(int idx, int dir){
    if (idx == N) return 0;
    if (d[idx][dir] != INF) return d[idx][dir];

    d[idx][dir] = 0;
    ll mv = INF;
    for (int i=0; i<=4; i++){
        if (pos[idx+1][i].X == INF) continue;

        mv = min(mv, move(idx+1, i) + dist(pos[idx][dir].X, pos[idx][dir].Y, pos[idx+1][i].X, pos[idx+1][i].Y));
    }

    return d[idx][dir] += mv;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int a, b;
    cin >> pos[0][0].X >> pos[0][0].Y;
    for (int i=1; i<=4; i++) pos[0][i] = {INF, INF};
    for (int i=1; i<=N; i++){
        cin >> a >> b;
        for (int dir=0; dir<=4; dir++){
            int nx = a + dx[dir];
            int ny = b+ dy[dir];
            if (OOB(nx, ny)) pos[i][dir] = {INF, INF};
            else pos[i][dir] = {nx, ny};
        }
    }
    
    for (int i=0; i<=N; i++) fill(d[i], d[i]+5, INF);
    cout << move(0, 0);
    

    return 0;
}