#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
#define ll long long
#define X first
#define Y second

struct R
{
    int x, y;
    int pid, count;
    R() = default;
    R(int a, int b, int c, int e)
    {
        x = a;
        y = b;
        pid = c;
        count = e;
    }
    bool operator<(const R &r) const
    {
        if (count != r.count)
            return count > r.count;
        if (x + y != r.x + r.y)
            return x + y > r.x + r.y;
        if (x != r.x)
            return x > r.x;
        if (y != r.y)
            return y > r.y;
        return pid > r.pid;
    }
};

int dx[4] = {-1, 0, 1, 0}; // 짝수: 상하 / 홀수: 좌우
int dy[4] = {0, -1, 0, 1};

int N, M, P;
priority_queue<R> pq; // 최대힙
map<int, ll> score;   // {pid, score}
map<int, int> dist;   // {pid, dist}
vector<int> pid_v;

void print()
{
    if (pq.empty())
        return;
    auto p = pq.top();
    cout << "------------------------" << '\n';
    cout << "pid = " << p.pid << '\n';
    cout << "x, y = " << p.x << ", " << p.y << '\n';
    cout << "count = " << p.count << '\n';
    cout << "------------------------" << '\n';
}

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.X + a.Y != b.X + b.Y)
        return a.X + a.Y > b.X + b.Y;
    else if (a.X != b.X)
        return a.X > b.X;
    else
        a.Y > b.Y;
}

void get_winner(unordered_map<int, R> selected, int S)
{
    R winner = selected.begin()->second;
    for (auto it = selected.begin(); it != selected.end(); it++)
    {
        R r = it->second;
        if (winner.x + winner.y < r.x + r.y)
        {
            if (winner.x + winner.y < r.x + r.y)
                winner = r;
            continue;
        }
        if (winner.x != r.x)
        {
            if (winner.x < r.x)
                winner = r;
            continue;
        }
        if (winner.y != r.y)
        {
            if (winner.y < r.y)
                winner = r;
            continue;
        }
        if (winner.pid < r.pid)
            winner = r;
    }
    // cout << "winner " << winner.pid << " : " << score[winner.pid] << "<- + " << S << '\n';
    score[winner.pid] += S;
}

bool OOB(int x, int y)
{
    if (x < 0 || x >= N || y < 0 || y >= M)
        return true;
    return false;
}

pair<int, int> move(int d, int dir, int x, int y)
{
    // d <= 10억 -> 그냥 이동하면 시간초과
    if (dir % 2 == 0)
        d %= (2 * N - 2);
    else
        d %= (2 * M - 2);

    int nx, ny;
    while (true)
    {
        nx = x + d * dx[dir];
        ny = y + d * dy[dir];
        if (!OOB(nx, ny))
            break;

        if (dir == 0)
        { // 상
            d -= x;
            x = 0;
        }
        else if (dir == 1)
        { // 좌
            d -= y;
            y = 0;
        }
        else if (dir == 2)
        { // 하
            d -= N - 1 - x;
            x = N - 1;
        }
        else
        { // 우
            d -= M - 1 - y;
            y = M - 1;
        }
        dir = (dir + 2) % 4;
    }
    return {nx, ny};
}

int main()
{
    int K, S, Pit, L;
    int Q;
    cin >> Q;
    Q -= 2;
    int cmd;
    cin >> cmd >> N >> M >> P;
    int pid, d;
    for (int i = 0; i < P; i++)
    {
        cin >> pid >> d;
        R r = R(0, 0, pid, 0); // {x, y, pid, count}
        dist[pid] = d;
        pq.push(r);
        pid_v.push_back(pid);
    }
    while (Q--)
    {
        cin >> cmd;
        if (cmd == 200)
        {
            cin >> K >> S;
            unordered_map<int, R> selected;
            while (K--)
            {
                // print();
                auto r = pq.top();
                pq.pop();

                vector<pair<int, int>> pos_v;
                for (int dir = 0; dir < 4; dir++)
                {
                    pair<int, int> pos = move(dist[r.pid], dir, r.x, r.y);
                    pos_v.push_back({pos.X, pos.Y});
                }

                // for (int i=0; i<4; i++) cout << "\tpos = " << pos_v[i].X << ", " << pos_v[i].Y << '\n';
                sort(pos_v.begin(), pos_v.end(), cmp);

                // 다른 토끼들 점수 얻기
                for (int &id : pid_v)
                {
                    if (id == r.pid)
                        continue;
                    score[id] += pos_v[0].X + pos_v[0].Y + 2;
                }
                // 결정된 토끼 다시 넣기
                r = R(pos_v[0].X, pos_v[0].Y, r.pid, r.count + 1);
                pq.push(r);

                selected[r.pid] = r;
            }
            // S 더해주기
            get_winner(selected, S);
        }
        else if (cmd == 300)
        {
            cin >> Pit >> L;
            dist[Pit] *= L;
            // cout << "300 : " << Pit << " dist = " << dist[Pit] << '\n';
        }
    }
    cin >> cmd;

    ll answer = 0;
    for (int &id : pid_v)
    {
        if (answer < score[id])
            answer = score[id];
    }
    cout << answer;

    return 0;
}