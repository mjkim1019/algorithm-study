#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cost[1001];
int customer[1001];

// 구) 최소비용으로 C명의 고객 늘리기
// d[k] : 비용 k일 때 얻을 수 있는 최대 고객수
int d[100005]; // 1000*100

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int C, N;
    cin >> C >> N;
    for (int i=0; i<N; i++){
        cin >> cost[i] >> customer[i]; 
    }

    for (int i=0; i<N; i++){
        for (int k=1; k<=100000; k++){
            if (k-cost[i] < 0) continue;
            d[k] = max(d[k], d[k-cost[i]] + customer[i]);
        }
    }

    for (int k=1; k<=100000; k++){
        if (d[k] >= C) {
            cout << k; 
            return 0;
        }
    }
    

    return 0;
}