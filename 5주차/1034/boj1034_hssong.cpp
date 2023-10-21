// 램프
#include<iostream>
#include<algorithm>

using namespace std;

int N, M, K, result, sum, cnt;
string s[51];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> s[i];
    }
    cin >> K;
    for(int i = 0; i < N; i++){
        cnt = 0;
        for(int j = 0; j < M; j++){
            if(s[i][j] == '0'){
                cnt++;
            }
        }
        sum = 0;
        if(cnt <= K && cnt % 2 == K % 2){
            for(int j = 0; j < N; j++){
                if(s[i] == s[j]){
                    sum++;
                }
            }
        }
        result = max(result, sum);
    }
    cout << result;
}