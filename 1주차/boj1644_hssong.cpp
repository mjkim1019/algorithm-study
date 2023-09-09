// 소수의 연속합
#include<iostream>

using namespace std;

int check[4000001];
int prime[2000000];

int main(){
    int result = 0, num = 0;
    int N;
    cin >> N;
    check[1] = 1;
    // N보다 작은 소수를 prime 배열에 저장
    for(int i = 2; i <= N; i++){
        if(check[i] == 1){
            continue;
        }
        else{
            prime[num++] = i;
            for(int j = i; j <= N; j += i){
                check[j] = 1;
            }

        }
    }
    // 순차적으로 연속합이 넘어가면 처음 수를 증가시키고
    // 연속합이 같다면 결과 개수 1 증가
    for(int i = 0; i < num; i++){
        int sum = 0;
        for(int j = i; j < num; j++){
            sum += prime[j];
            if(sum > N){
                break;
            }
            else if(sum == N){
                result++;
            }
        }
    }
    cout << result << endl;
}