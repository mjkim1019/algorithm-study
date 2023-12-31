#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int N, M, K;
int board[11][11];
vector<pair<int, int>> people;
pair<int, int> exit_pos;

// 상, 하, 좌, 우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool OOB(int x, int y)
{
    if (x < 1 || x > N || y < 1 || y > N)
        return true;
    return false;
}

bool find_square(int n, int x, int y)
{
    bool is_find_p = false;
    bool is_find_exit = false;

    for (int i = x; i < x + n; i++)
    {
        if (is_find_p && is_find_exit) return true;
        for (int j = y; j < y + n; j++)
        {
            if (is_find_p && is_find_exit) return true;
            if (i == exit_pos.X && j == exit_pos.Y)
                is_find_exit = true;
            for (auto &p : people)
                if (i == p.X && j == p.Y)
                    is_find_p = true;
        }
    }
    if (is_find_p && is_find_exit)
        return true;

    return false;
}

void rotate(int a, int b, int n)
{
    int tmp[11][11];
    int rot[11][11];

    // 돌릴 부분만 복사
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            tmp[i][j] = board[i+a][j+b];

    // 돌리기
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            rot[i][j] = tmp[n-j-1][i];

    // 붙여넣기 & 내구성 감소시키기
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            board[i+a][j+b] = rot[i][j];
            if (board[i+a][j+b] > 0) --board[i + a][j + b]; 
        }
    }
    

    // 좌표 회전!
    // 출구
    exit_pos = {exit_pos.Y + a-b, n - exit_pos.X + 1 + a+b-2};

    // 사람들
    for (auto &p : people)
    {
        if (p.X == 0 && p.Y == 0) continue;
        if (p.X >= a && p.X < a + n && p.Y >= b && p.Y < b + n)
            p = {p.Y + a-b, n-p.X+1 + a+b-2};
    }
}

bool every_exit()
{
    for (auto &e : people)
    {
        if (e.X == 0 && e.Y == 0) continue;
        else return false;
    }
    return true;
}

void dfs(int L, int sum)
{
    if (L == K || every_exit())
    {
        cout << sum << '\n';
        cout << exit_pos.X << ' ' << exit_pos.Y;
        return;
    }

    // 1. 이동
    for (auto &p : people)
    {
        if (p.X == 0 && p.Y == 0) continue; // 이미 exit
        int dist = abs(p.X - exit_pos.X) + abs(p.Y - exit_pos.Y);
        pair<int, int> np = {0, 0};
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = p.X + dx[dir];
            int ny = p.Y + dy[dir];
            if (OOB(nx, ny)) continue;
            if (board[nx][ny] != 0) continue;
            if (nx == exit_pos.X && ny == exit_pos.Y){ // 탈출
                sum++;
                p = {0, 0};
                break;
            }
            int n_dist = abs(nx - exit_pos.X) + abs(ny - exit_pos.Y);
            if (n_dist < dist) {
                np = {nx, ny};
                dist = n_dist;
            }
        }
        if (np.X != 0 && np.Y != 0){
            p = np;
            sum++;
        }
    }
    
    // 2. 회전
    // 2-1. 가장 작은 정사각형 찾기
    int nn, x, y;
    bool found = false;
    for (int n = 2; n <= N; n++)
    {
       if (found) break;
        for (int i = 1; i <= N - n + 1; i++)
        {
            if (found) break;
            for (int j = 1; j <= N - n + 1; j++)
            {
                if (found) break;
                if (find_square(n, i, j))
                {
                    nn = n;
                    x = i;
                    y = j;
                    found = true;
                    break;
                }
            }
        }
    }
    if (!found){
        cout << sum << '\n';
        cout << exit_pos.X << ' ' << exit_pos.Y;
        return;
    }
    
    // 2-2. 정사각형 회전 & 내구성 감소시키기
    rotate(x, y, nn);
    dfs(L + 1, sum);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];
    int x, y;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        people.push_back({x, y});
    }
    cin >> x >> y;
    exit_pos = {x, y};
    dfs(0, 0);

    return 0;
}