// 이중 우선순위 큐
#include<iostream>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

int T, k;

void func();

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for(int i = 0; i < T; i++){
        func();
    }
}

void func(){
    priority_queue<int, vector<int>, greater<int>> min;
    priority_queue<int, vector<int>, less<int>> max;
    map<int, int> cnt;
    int index = 0;
    int a;
    char c;
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> c >> a;
        if(c == 'I'){
            min.push(a);
            max.push(a);
            cnt[a]++;
            index++;
        }
        else if(c == 'D'){
            if(a == -1){
                if(!min.empty()){
                    cnt[min.top()]--;
                    min.pop();
                    index--;
                }
            }
            else{
                if(!max.empty()){
                    cnt[max.top()]--;
                    max.pop();
                    index--;
                }
            }
            while(!min.empty() && cnt[min.top()] == 0){
                min.pop();
            }
            while(!max.empty() && cnt[max.top()] == 0){
                max.pop();
            }
        }
    }
    if(index <= 0){
        cout << "EMPTY\n";
    }
    else{
        cout << max.top() << " " << min.top() << "\n";
    }
    return;
}