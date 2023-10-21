#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

vector<pair<int, int>> adj[101]; // cost, 번호
vector<bool> vis(101);

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;

    for (auto &v : costs)
    {
        adj[v[0]].push_back({v[2], v[1]});
        adj[v[1]].push_back({v[2], v[0]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vis[0] = true;
    for (auto &v : adj[0])
    {
        pq.push(v);
    }

    int cnt = 1;
    while (cnt < n && !pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if (vis[cur.Y])
            continue;
        vis[cur.Y] = true;
        cnt++;
        answer += cur.X;
        for (auto &v : adj[cur.Y])
        {
            if (vis[v.Y]) continue;
            pq.push(v);
        }
    }

    return answer;
}