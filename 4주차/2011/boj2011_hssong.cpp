// 암호코드
#include<iostream>

using namespace std;

string input;
int dp[5001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> input;
    if(input[0] == '0'){
        cout << 0;
        return 0;
    }
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 0; i < input.length() - 1; i++){
        if(input[i + 1] != '0'){
            dp[i + 2] = dp[i + 1] % 1000000;
        }
        int temp = (input[i] - '0') * 10 + (input[i + 1] - '0');
        if(temp >= 10 && temp <= 26){
            dp[i + 2] = (dp[i + 2] + dp[i]) % 1000000;
        }
    }
    cout << dp[input.length()];
}