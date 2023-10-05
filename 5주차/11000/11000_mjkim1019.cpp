#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int answer = 0;

    int N; cin >> N;
    vector<tuple<int, int, int>> v; // 시간, 인덱스, 타입(시작:1, 끝:0)
    for (int i=0; i<N; i++){
        int st, en;
        cin >> st >> en;
        v.push_back({st, i, 1});
        v.push_back({en, i, 0});
    }
    sort(v.begin(), v.end());

    set<int> s; // 진행중인 수업의 인덱스
    for (int i=0; i<v.size(); i++){
        int t, idx, type;
        tie(t, idx, type) = v[i];
        if (type == 1){
            s.insert(idx);
        }else {
            s.erase(idx);
        }   
        int cnt = s.size();
        answer = max(cnt, answer);
    }
    cout << answer;
    

    return 0;
}