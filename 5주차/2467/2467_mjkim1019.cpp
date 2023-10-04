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

    // 두 개의 용액 선택 -> 투포인터
    int l=0, r= v.size()-1; 
    while (l < r){
        ll sum = v[l]+v[r]; 
        if (abs(sum) < mn){ 
            mn = abs(sum);
            answer = {v[l], v[r]};
        } 
        if (sum == 0) break;
        else if (sum < 0) l++; // 음수면 값을 크게 만들어주기 위해 -값 작게(숫자 크게)
        else r--; // 양수면 값을 작게 만들어주기 위해 +값 작게
    }

    sort(answer.begin(), answer.end());
    cout << answer[0] << ' ' << answer[1];

    return 0;
}