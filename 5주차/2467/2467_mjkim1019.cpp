#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<ll> answer(2);
    ll mn = 2e9;

    int N; cin >> N;
    vector<ll> v(N);
    for (int i=0; i<N; i++) cin >> v[i];
    sort(v.begin(), v.end());

    for (int i=0; i<v.size(); i++){
        auto it = lower_bound(v.begin()+i+1, v.end(), -v[i]);
        if (it != v.end()) {
            if (mn > abs(v[i] + *it)){
                mn = abs(v[i] + *it);
                answer = {*it, v[i]};
                //cout << v[i] << ' ' << *it << "= " << mn <<'\n';
            }
        }
        
        if (i+1 != (it-v.begin()) && mn > abs(v[i] + *(--it))){
            mn = abs(v[i] + *it);
            answer = {*it, v[i]};
            //cout << v[i] << ' ' << *it << "= " << mn << '\n';
        }
        if (mn == 0) break;
    }
    sort(answer.begin(), answer.end());
    cout << answer[0] << ' ' << answer[1];

    return 0;
}