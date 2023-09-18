// 숨바꼭질 3
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool visit[100001];

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

int main(){
    int N, K, result = 0;
    // 우선 순위 큐로 첫번째 요소는 오름차순 두번째 요소는 내림차순으로 비교
    priority_queue<pair<int, int>, vector<pair<int,int>>, Compare> q;
    cin >> N >> K;
    // 수빈이 동생을 찾아가는 것과 동생이 수빈을 찾아가는 것은 역으로 같기 때문에
    // 나누기가 편할 것 같아서 동생이 수빈을 찾아가도록 코드를 짬
    // 따라서 우선순위 큐의 첫번째 요소는 걸리는 시간으로 해서 오름차순을 정렬했고
    // 두번째 요소는 동생의 위치로 했음
    // 만약 두번째 요소가 오름차순이라면 텔레포트를 한 다음 시간이 늘어나지 않아
    // 다시 우선순위가 되어 계속 텔레포트나 다른 이동을 하게 됨으로 결과가 원하는대로
    // 나오지 않아서 내림차순으로 정렬하게 함
    q.push({0, K});
    visit[K] = true;
    while(!q.empty()){
        result = q.top().first;
        K = q.top().second;
        q.pop();
        if(N == K){
            cout << result << endl;
            break;
        }
        // 텔레포트 할 경우
        if(K % 2 == 0 && K > N && !visit[K / 2]){
            q.push({result, K / 2});
            visit[K / 2] = true;
        }
        // 수빈이와 멀어질 경우
        if(K + 1 <= 100000 && !visit[K + 1]){
            q.push({result + 1, K + 1});
            visit[K + 1] = true;
        }
        // 수빈이와 가까워질 경우
        if(K - 1 >= 0 && !visit[K - 1]){
            q.push({result + 1, K - 1});
            visit[K - 1] = true;
        }
    }

    // 이전에 풀다가 실패한 방식
    // while(N != q.top().second){
    //     result = q.top().first;
    //     K = q.top().second;
    //     q.pop();
    //     if(K < N){
    //         result += N - K;
    //         break;
    //     }
    //     if(K % 2 == 0){
    //         if(N > K / 2){
    //             if(K - N > N - K / 2){
    //                 result += N - K / 2;
    //             }
    //             else{
    //                 result += K - N;
    //             }
    //             break;
    //         }
    //         else{
    //             q.push({result, K/2});
    //         }
    //     }
    //     if(K+1 <= 100000 && !visit[K+1]){
    //         q.push({result+1, K+1});
    //         visit[K+1] = true;
    //     }
    //     if(K-1 >= 0 && !visit[K-1]){
    //         q.push({result+1, K-1});
    //         visit[K-1] = true;
    //     }
    // }
    // cout << result;
}