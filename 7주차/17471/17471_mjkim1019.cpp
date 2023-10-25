#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f

int N;
int people[11];
vector<int> adj[11];
bool vis[11];
int answer = INF;
int total = 0;

bool is_valid(vector<int> &v, bool flag){
    vector<bool> check(N+1, false);

    queue<int> Q;
    check[v[0]] = true;
    Q.push(v[0]);
    int cnt = 1;
    while (!Q.empty()){
        int cur = Q.front(); Q.pop();
        for (int &e: adj[cur]){
            if (check[e] == false && vis[e] == flag) {
                check[e] = true;
                Q.push(e);
                cnt++;
            }
        }
    }

    if (v.size() == cnt) return true;
    return false;
}

bool is_two_group(){
    vector<int> a, b;
    for (int i=1; i<=N; i++){
        if (vis[i]) a.push_back(i);
        else b.push_back(i);
    }
    if (a.empty() || b.empty()) return false;
    if (is_valid(a, true) == false) return false;
    if (is_valid(b, false) == false) return false;
    
    return true;
}

int cal(){
    int sum1 = 0;
    int sum2 = 0;
    for (int i=1; i<=N; i++){
        if (vis[i]) sum1 += people[i];
        else sum2 += people[i];
    }
    return abs(sum1 - sum2);
}

void func(int L, int cur) {
    
    if (L >= 1 && is_two_group()) {
        //cout << sum << " - " << total-sum << '\n';
        answer = min(answer, cal());
    }
    if (L == N) return;

    for (int i=cur; i<N; i++){
        if (vis[i]) continue;
        vis[i] = true;
        func(L+1, i+1);
        vis[i] = false;
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

    func(0, 1);

    if (answer == INF) cout << -1;
    else cout << answer;

    return 0;
}