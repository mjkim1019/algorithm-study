// 카드 정렬하기
#include<iostream>
#include<queue>

using namespace std;

int N, result;
priority_queue<int, vector<int>, greater<int>> q;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int input, a, b;
    cin >> N;
    // 한 묶음만 있을 때는 비교할 필요가 없어서 0을 출력한다
    if(N == 1){
        cin >> input;
        cout << 0;
        return 0;
    }
    for(int i = 0; i < N; i++){
        cin >> input;
        q.push(input); 
    }
    while(1){
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        result += a + b;
        if(q.empty()){
            break;
        }
        q.push(a+b);
    }
    cout << result;
}