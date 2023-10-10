#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int answer = 0;

    int n, m;
    cin >> n >> m;
    vector<int> plus;
    vector<int> minus;

    int tmp;
    for (int i=0; i<n; i++){
        cin >> tmp;
        if (tmp > 0) plus.push_back(tmp);
        else minus.push_back(-tmp);
    }

    sort(plus.begin(), plus.end(), greater<>());
    sort(minus.begin(), minus.end(), greater<>());

    for (int i=0; i<plus.size(); i += m){
        answer += plus[i]*2;
    }

    for (int i=0; i<minus.size(); i += m) {
        answer += minus[i]*2;
    }

    int a=0, b=0;
    if (!plus.empty()) a = plus[0];
    if (!minus.empty()) b = minus[0];

    if (a > b) answer -= a; // b 먼저
    else answer -= b; // a 먼저

    cout << answer;

    return 0;
}