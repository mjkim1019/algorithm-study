// 두 동전
#include<iostream>
#include<queue>

using namespace std;

bool visited[21][21][21][21];
char m[21][21];
int N, M;
int x1, y1, x2, y2;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct Coin{
    int x1, y1, x2, y2, cnt;
};

bool isOut(int, int);
int bfs();

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int num = 0;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> m[i][j];
            if(m[i][j] == 'o'){
                if(num == 0){
                    x1 = i;
                    y1 = j;
                    num = 1;
                }
                else{
                    x2 = i;
                    y2 = j;
                }
            }
        }
    }
    cout << bfs() << '\n';
}

bool isOut(int x, int y){
    if(x < 0 || x >= N || y < 0 || y >= M){
        return true;
    }
    return false;
}

int bfs(){
    queue<Coin> q;
    q.push({x1, y1, x2, y2, 0});
    while(!q.empty()){
        Coin now = q.front();
        q.pop();

        visited[now.x1][now.y1][now.x2][now.y2] = true;
        if(now.cnt >= 10) return -1;

        for(int i = 0; i < 4; i++){
            int nx1 = now.x1 + dx[i];
            int ny1 = now.y1 + dy[i];
            int nx2 = now.x2 + dx[i];
            int ny2 = now.y2 + dy[i];

            // 동전이 하나만 떨어진 경우
            if(!isOut(nx1, ny1) && isOut(nx2, ny2) || isOut(nx1, ny1) && !isOut(nx2, ny2)){
                return now.cnt + 1;
            }

            // 동전이 둘 다 떨어진 경우
            if(isOut(nx1, ny1) && isOut(nx2, ny2)){
                continue;
            }

            if(m[nx1][ny1] == '#'){
                nx1 = now.x1;
                ny1 = now.y1;
            }
            if(m[nx2][ny2] == '#'){
                nx2 = now.x2;
                ny2 = now.y2;
            }
            if(visited[nx1][ny1][nx2][ny2]){
                continue;
            }

            q.push({nx1, ny1, nx2, ny2, now.cnt + 1});
        }
    }
    return -1;
}