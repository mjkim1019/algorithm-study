#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1. 좋아하는 학생이 가장 많이 인접한 칸
// 2. 인접한 칸 중 비어있는 칸이 가장 많은 칸
// 3. 행 번호 가장 작은, 열 번호 가장 작은 칸

int N;
int seat[25][25]; // 앉은 사람 번호
int love[500][4]; // 좋아하는 사람 번호

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct Pos{
    int likes, empty, r, c;
    Pos(int l, int e, int x, int y){
        likes = l;
        empty = e;
        r = x;
        c = y;
    }

    bool operator<(const Pos &pos) const{
        if (likes == pos.likes){
            if (empty == pos.empty){
                if (r == pos.r) return c < pos.c;
                else return r < pos.r;
            }
            else return empty > pos.empty;
        }
        else return likes > pos.likes;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int answer = 0;

    cin >> N;
    int num, a, b, c, d;
    for (int n=0; n<N*N; n++){
        cin >> num >> a >> b >> c >> d;
        love[num][0] = a;
        love[num][1] = b;
        love[num][2] = c;
        love[num][3] = d;

        vector<Pos> v;
       
        for (int i=1; i<= N; i++){
            for (int j=1; j<=N; j++){
                if (seat[i][j] != 0) continue; // 앉을 수 없는 자리 (이미 앉은 사람 있음)

                int likes = 0;
                int empty = 0;
                for (int dir=0; dir<4; dir++){
                    int nx = i+dx[dir];
                    int ny = j+dy[dir];
                    if (nx <1 || nx>N || ny<1 || ny>N) continue;
                    if (seat[nx][ny] == a || seat[nx][ny] == b || seat[nx][ny] == c || seat[nx][ny] == d) likes++;
                    else if (seat[nx][ny] == 0) empty++;
                }
                v.push_back(Pos(likes, empty, i, j));
            }
        }

        sort(v.begin(), v.end());
        Pos pos = v[0];
        seat[pos.r][pos.c] = num;
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++){
            int num = seat[i][j];
            int cnt = 0;
            for (int dir = 0; dir<4; dir++){
                int nx = i+dx[dir];
                int ny = j+dy[dir];
                if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
                for (int k=0; k<4; k++){
                    if (love[num][k] == seat[nx][ny]) cnt++;
                }
            }
            if (cnt == 1) answer += 1;
            else if (cnt == 2) answer += 10;
            else if (cnt == 3) answer += 100;
            else if (cnt == 4) answer += 1000;
        }
    }
    cout << answer;

}