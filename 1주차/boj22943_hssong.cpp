// 수
#include<iostream>

using namespace std;

int check[50001];
int prime[50001];

void SetPrime(int);
bool IsPrime(int);
bool Check1(int);
bool Check2(int, int);
bool Check_default(int, int);

int main(){
    int K, M, min = 1, max = 9, p = 2, q = 8, result = 0;;
    cin >> K >> M;
    for(int i = 1; i < K; i++){
        if(i == 1){
            min = 10;
        }
        else{
            min = min * 10 + p++;
        }
        max = max * 10 + q--;
    }
    SetPrime(98765);
    for(int i = min; i <= max; i++){
        if(Check2(i, M) && Check1(i) && Check_default(i, K)){
            result++;
        }
        // if(Check_default(i, K)){
        //     cout << "check3 " << i << " ";
        // }
        // if(Check1(i)){
        //     cout << "check1 " << i << " ";
        // }
        // if(Check2(i, M)){
        //     cout << "check2 " << i << " ";
        // }
        // cout << endl;
    }
    cout << result;
}

void SetPrime(int max){
    int num = 0;
    check[1] = 1;
    for(int i = 2; i <= max / 2; i++){
        if(check[i] == 1){
            continue;
        }
        else{
            prime[num++] = i;
            for(int j = i; j <= max / 2; j += i){
                check[j] = 1;
            }
        }
    }
}

bool IsPrime(int num){
    int i = 0;
    while(1){
        if(prime[i] > num){
            return false;
        }
        else{
            if(prime[i] == num){
                return true;
            }
            else{
                i++;
            }
        }
    }
}

bool Check1(int num){
    int i = 0;
    while(1){
        if(prime[i] > num  || prime[i] == 0){
            return false;
        }
        else{
            if(IsPrime(num - prime[i]) && prime[i] != num - prime[i]){
                return true;
            }
            else{
                i++;
            }
        }
    }
}

bool Check2(int num, int M){
    while(!(num % M)){
        num = num / M;
    }
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0 && IsPrime(i) && IsPrime(num / i)){
            return true;
        }
    }
    return false;
}

bool Check_default(int num, int K){
    int m[10] = {0};
    for(int i = 0; i < K; i++){
        if(m[num % 10] == 1){
            return false;
        }
        else{
            m[num % 10]++;
            num = num / 10;
        }
    }
    return true;
}

// 계속 시간 초과가 나는데 어디를 어떻게 수정해서
// 성능을 향상시켜야 할 지 모르겠어서 포기