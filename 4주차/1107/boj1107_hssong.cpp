// 리모컨
#include<iostream>
#include<algorithm>


using namespace std;

int N, M;
bool m[10];

bool check(string);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> N;
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> n;
        m[n] = true;
    }
    int result = abs(100 - N);
    if(result <= 2){
        cout << result;
        return 0;
    }
    for(int i = 0; i <= 999999; i++){
        if(check(to_string(i))){
            result = min(result, int(abs(i - N) + to_string(i).length()));
        }
    }

    cout << result;
}

bool check(string s){
    for(int i = 0; i < s.length(); i++){
        if(m[s[i] - '0']){
            return false;
        }
    }
    return true;
}