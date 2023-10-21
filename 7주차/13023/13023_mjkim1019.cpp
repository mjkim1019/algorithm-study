#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_found = false;
vector<int> adj[2001];
vector<bool> vis(2001);

void func(int L, int x){
    if (is_found) return;

    if (L >= 4){
        is_found = true;
        return;
    }

    for (int &i: adj[x]){
        if (vis[i]) continue;
        vis[i] = true;
        func(L+1, i);
        vis[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int a, b;
    for (int i=0; i<M; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i=0; i<N; i++){
        if (is_found) break;
        if (adj[i].empty()) continue;
        vis[i] = true;
        func(0, i);
        vis[i] = false;
    }
    
    if (is_found) cout << 1;
    else cout << 0;

    return 0;
}