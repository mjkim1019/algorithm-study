#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int cost[1001];
vector<int> adj[1001];
int indegree[1001];
int d[1001]; // k 건물 건설완료하는데 드는 최소 시간

int answer = 0;
int N, K, W;

void init(){
    answer = 0;
    fill(indegree, indegree+N+1, 0);
    fill(d, d+N+1, 0);
    for (int i=1; i<=N; i++) adj[i].clear();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--){
    cin >> N >> K;
    init();
    for (int i=1; i<=N; i++) cin >> cost[i];
    for (int i=0; i<K; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    cin >> W;

    queue<int> Q;
    for (int i=1; i<=N; i++){
        if (indegree[i] != 0) continue;
        d[i] = cost[i];
        Q.push(i);
    }

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        //cout << cur << " : " << d[cur] << '\n';
        
        for (int &e: adj[cur]){
            --indegree[e];
            d[e] = max(d[e], d[cur] + cost[e]);
            if (indegree[e] != 0) continue;
            Q.push(e);
        }
        
    }
    cout << d[W] << '\n';
    }

    return 0;
}