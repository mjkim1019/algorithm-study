// 강의실 배정
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, b;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    pq.push(v[0].second);
    for(int i = 1; i < N; i++){
        a = v[i].first;
        b = v[i].second;
        pq.push(b);
        if(pq.top() <= a){
            pq.pop();
        }
    }
    cout << pq.size();
}