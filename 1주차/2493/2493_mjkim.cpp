#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<int> arr(N+1);
    for (int i=1; i<=N; i++) 
        cin >> arr[i];
    
    vector<int> answer(N+1);
    stack<int> s;
    for (int i=N; i>0; i--){
        while (!s.empty()){
            int t = s.top();
            if (arr[i] > arr[t]) {
                answer[t] = i;
                s.pop();
            }
            else break;
        }
        s.push(i);
    }
    
    for (int i=1; i<=N; i++) cout << answer[i] << ' ';

    return 0;
}