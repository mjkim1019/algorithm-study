// 감소하는 수
// 소수 때와 같이 감소하는 수를 순차적으로 저장을 해봤는데 시간초과가 발생하여
// 다른 방식으로 구현했다
// a는 배열에 저장할 위치, b는 가져올 배열의 위치
// 우선 0~9를 배열에 저장하고
// index 10 부터는 감소하는 수 뒤에 0~9를 붙였을 때도
// 감소하는 수인지 판별 후 저장하고 아니면 감소하는 수를 증가시키며
// 과정을 반복한다
#include<iostream>

using namespace std;

long long m[2000];

int main(){
    int N, a = 10, b = 1;
    cin >> N;
    if(N < 11){
        cout << N << endl;
        return 0;
    }
    for(int i = 0; i < 10; i++){
        m[i] = i;
    }
    while(1){
        for(int i = 0; i < 10; i++){
            if(i < m[b] % 10){
                m[a] = m[b] * 10 + i;
                if(a == N){
                    cout << m[a] << endl;
                    return 0;
                }
                if(m[a] == 9876543210){
                    cout << -1 << endl;
                    return 0;
                }
                a++;
            }
            else{
                b++;
                break;
            }
        }
    }
}



// 1021 987654321
// 1022 9876543210