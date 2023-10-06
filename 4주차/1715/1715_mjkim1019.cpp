#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    priority_queue<int, vector<int>, greater<>> pq; // 최소힙
    for (int i=0; i<N; i++) {
        int tmp; cin >> tmp;
        pq.push(tmp);
    }

    int answer = 0;
    while (pq.size() >= 2){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        answer += a+b;
        pq.push(a+b);
    }
    cout << answer;


    return 0;
}