// 구) 모든 두 집 쌍이 불 켜진 길로 왕래할 수 있게, 절약할 수 있는 최대 액수는?
// 최소신장트리 - 프림(우선순위큐)

#include <bits/stdc++.h>
using namespace std;

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        int M, N; // 집의 수, 길의 수
        cin >> M >> N;
        if (M == 0 && N == 0) break;

        vector<bool> chk(M+1);
        vector<pair<int, int>> adj[M+1]; // 집번호1 : {거리, 집번호2}

        int a, b, c;
        int total = 0;
        for (int i = 0; i < N; i++){
            cin >> a >> b >> c;
            adj[a].push_back({c, b});
            adj[b].push_back({c, a});
            total += c;
        }

        chk[0] = true;
        for (auto e : adj[0])
            pq.push({e.first, 0, e.second});

        int answer = 0;
        while (!pq.empty()){
            int dist, a, b;
            tie(dist, a, b) = pq.top(); pq.pop();
            if (chk[b]) continue;
            chk[b] = true;
            answer += dist;
            for (auto e : adj[b]){
                if (chk[e.second]) continue;
                pq.push({e.first, b, e.second});
            }
        }
        cout << total - answer << '\n';
    }

    return 0;
}