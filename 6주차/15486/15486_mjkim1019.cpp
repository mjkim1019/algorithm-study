// 퇴사2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> t(N+1);
    vector<int> p(N+1);
    for (int i=1; i<=N; i++){
        cin >> t[i] >> p[i];
    }

    // 앞에서부터 시작하면 k일이 가능한지 아닌지 계속 t보면서 체크해줘야함
    // -> 뒤에서부터 시작
    // d[k] : k일에 시작했을 때 얻을 수 있는 최대 수익
    vector<int> d(N+2);
    for (int k=N; k>=1; k--){
        if (k + t[k] <= N+1) {
            d[k] = max(p[k] + d[k+t[k]], d[k+1]);
        }
        else d[k] = d[k + 1];
    }
    cout << *max_element(d.begin(), d.end());

    return 0;
}