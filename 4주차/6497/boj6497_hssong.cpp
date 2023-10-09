// 전력난
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int parent[200001];

int m, n;

int findParent(int);
void unionParent(int, int);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(true){
        cin >> m >> n;
        if(m == 0 && n == 0){
            break;
        }
        int total = 0;
        vector<pair<int, pair<int, int>>> v;

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        for(int i = 0; i < n; i++){
            int a, b, c;
            cin >> a >> b >> c;
            total += c;
            v.push_back({c, {a, b}});
        }
        sort(v.begin(), v.end());

        for(int i = 0; i < v.size(); i++){
            int a = v[i].second.first;
            int b = v[i].second.second;
            int c = v[i].first;

            if(findParent(a) != findParent(b)){
                total -= c;
                unionParent(a, b);
            }
        }
        cout << total << '\n';
    }
}

int findParent(int n){
    if(n == parent[n]) return n;
    else return parent[n] = findParent(parent[n]);
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);

    if(a < b) parent[b] = a;
    else parent[a] = b;
}