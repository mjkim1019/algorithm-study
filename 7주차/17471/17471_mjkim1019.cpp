#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int people[11];
vector<int> adj[11];
bool vis[11];
int answer = 100;
int total = 0;

bool is_valid(){
    bool check[11];

    queue<int> Q;
    for (int i=1; i<=N; i++) {
        check[i] = vis[i];
        if (Q.empty() && check[i] == false) {
            check[i] = true;
            Q.push(i);
        }
    }

    while (!Q.empty()){
        int cur = Q.front(); Q.pop();
        for (int &e: adj[cur]){
            if (check[e]) continue;
            check[e] = true;
            Q.push(e);
        }
    }

    for (int i=1; i<=N; i++){
        if (check[i] == false) return false;
    }
    return true;
}

void func(int cur, int sum) {
    if (total != sum && is_valid()) {
        answer = min(answer, abs(total-sum-sum));
    }

    for (int &e: adj[cur]){
        if (vis[e]) continue;
        vis[e] = true;
        func(e, sum+people[e]);
        vis[e] = false;
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> people[i];
        total += people[i];
    }

    for (int i=1; i<=N; i++){
        int M; cin >> M;
        for (int j=0; j<M; j++){
            int e; cin >> e;
            adj[i].push_back(e);
        }
    }

    for (int i=1; i<=N; i++){
        fill(vis, vis+N+1, false);
        vis[i] = true;
        func(i, 0);
    }

    if (answer == 100) cout << -1;
    else cout << answer;

    return 0;
}