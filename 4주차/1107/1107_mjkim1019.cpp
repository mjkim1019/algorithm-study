#include <iostream>
#include <algorithm>
using namespace std;

bool broke[10];

bool is_valid(string s){
    for (int i=0; i<s.size(); i++) {
        if (broke[s[i]-'0']) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; 
    int M;
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int tmp; cin >> tmp;
        broke[tmp] = true;
    }

    int answer = abs(N - 100);
    if (answer <= 3) {
        cout << answer; return 0;
    }

    for (int i=0; i<1000000; i++){ // 1000000이어야 위의 값 입력후 내려가는 값까지 생각할 수 있음
        if (!is_valid(to_string(i))) continue;
        int len = to_string(i).length();
        answer = min(answer, abs(i-N)+len);
    }

    cout << answer;



    return 0;
}