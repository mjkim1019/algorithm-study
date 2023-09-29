#include <iostream>
using namespace std;
#define MOD 1000000

// dp 1.테이블 정의 2. 점화식 찾기 3. 초기값 설정
// 1. d[k] = k자리까지 나올 수 있는 해석의 가짓수
int d[5001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string num; cin >> num;
    if (num[0] == '0') { // 해석 불가
        cout << 0; return 0;
    }
    
    d[0] = 1; // d[0] = 1이어야지 d[2] = 2 나올 수 있음
    d[1] = 1;
    for (int k=2; k<=num.length(); k++){ // k는 자리수 (1부터 시작), 문자열은 0부터 시작 조심!
        if (num[k-1] != '0') d[k] = d[k-1] % MOD;
        int tmp = (num[k - 2] - '0') * 10 + num[k - 1] - '0';
        if (tmp >= 10 && tmp <= 26){ // 두자리니까 10부터
            d[k] = (d[k] + d[k - 2]) % MOD;
        }
    }
    cout << d[num.length()] % MOD;

    return 0;
}