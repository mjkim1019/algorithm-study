#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

vector<ll> v;

void dfs(int L, int N, string num){
    if (L==N){
       //cout << num << '\n';
        v.push_back(stoll(num));
        return;
    }

    for (int i=9; i>=0; i--){
        if (L==0){
            if (i != 0) dfs(L+1, N, to_string(i));
            continue;
        }

        if (num[L-1] - '0' > i) {
            dfs(L+1, N, num+to_string(i));
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    if (N<10) {
        cout << N; return 0;
    }

    for (int i=2; i<=10; i++){ // 자리수
        dfs(0, i, "");
        if (v.size() > N-10) {
            sort(v.begin(), v.end());
            // for (auto e: v) cout << e << ' ';
            // cout << '\n';
            cout << v[N-10];
            return 0;
        }
    }

    cout << "-1";

    return 0;
}