#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define X first
#define Y second

int N;
vector<pair<int, int>> arr;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int r, c;
    cin >> r >> c;
    int mx_x = 0, mx_y = 0;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        mx_x = max(mx_x, a);
        mx_y = max(mx_y, b);
        arr.push_back({a, b});
    }
    
    vector<vector<int>> d(mx_x+1, vector<int>(mx_y+1, -1));
    d[r][c] = 0;
    queue<pair<int, int>> Q;
    Q.push({r, c});
    while (!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        //cout << cur.X << ", " << cur.Y << '\n';
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx > mx_x || ny < 0 || ny > mx_y) continue;
            if (d[nx][ny] >= 0) continue;
            d[nx][ny] = d[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    pair<int, int> pos;
    pair<int, int> ex = {r, c};
    int answer = 0;
    for (auto &cur : arr)
    {
        pos = cur;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx > mx_x || ny < 0 || ny > mx_y) continue;

            if (d[nx][ny] < d[pos.X][pos.Y]) pos = {nx, ny};
        }
        cout << pos.X  << "," << pos.Y << '\n';
        cout << d[pos.X][pos.Y] << "-" << d[ex.X][ex.Y] << "= " << d[pos.X][pos.Y] - d[ex.X][ex.Y] << '\n';
        answer += abs(d[pos.X][pos.Y] - d[ex.X][ex.Y]);
        ex = pos;
    }
    cout << answer;

    return 0;
}