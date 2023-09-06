#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1e5+1

vector<int> d(300000, INF);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    d[N] = 0;
    queue<int> q;
    q.push(N);
    while (!q.empty() && q.front() != K){
        int cur = q.front(); q.pop();
        if (cur-1 >= 0){
            if (d[cur-1] > d[cur]+1){
                //cout << "cur-1 = " << cur-1 << '\n';
                d[cur-1] = d[cur]+1;
                q.push(cur-1);
            }
        }
        if (cur+1 <= 1e5){
            if (d[cur+1] > d[cur]+1){
                //cout << "cur+1 = " << cur + 1 << '\n';
                d[cur+1] = d[cur]+1;
                q.push(cur+1);
            }
        }
        if (cur*2 <= 1e5){
            if (d[cur*2] > d[cur]) {
                //cout << "cur*2 = " << cur * 2 << '\n';
                d[cur*2] = d[cur];
                q.push(cur*2);
            }
        }
    }
    cout << d[K];

    return 0;
}