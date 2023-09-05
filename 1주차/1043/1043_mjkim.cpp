#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> p(55, -1);
vector<int> party[55];

int get_parent(int x){
    if (p[x] < 0) return x;
    return p[x] = get_parent(p[x]);
}

void merge_group(int u, int v){
    u = get_parent(u);
    v = get_parent(v);

    if (u == v) return;

    if (u < v) p[v] = u;
    else p[u] = v;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int answer =0;

    int M;
    cin >> N >> M;

    int X; cin >> X;
    while(X--){
        int n; cin >> n;
        p[n] = 0; // 0 집합으로
    }

    for (int i=0; i<M; i++){
        int n; cin >> n;
        vector<int> arr(n);
        for (int i=0; i<n; i++){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        party[i] = arr;
        for (int i=1; i<n; i++){
            merge_group(arr[0], arr[i]);
        }
    }

    for (int i=0; i<M; i++) {
        vector<int> pt = party[i];
        bool is_ok = true;
        for (int j=0; j<pt.size(); j++){
            if (get_parent(pt[j]) == 0) {
                is_ok = false; break;
            }
        }
        if (is_ok) answer++;
    }
    cout << answer;

    return 0;
}