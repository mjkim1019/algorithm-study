// 신기한 소수
// 1자리 소수를 큐에 저장한 후 각 소수 뒤에 1, 3, 7, 9를 붙였을 때
// 소수인지 판별하고 소수라면 큐에 저장을 한다
// 만약 큐에 저장된 소수의 자릿수와 입력된 N의 값이 같으면
// 작업을 그만 두고 저장된 큐의 값들을 출력한다
#include<iostream>
#include<queue>

using namespace std;

bool isPrime(int);
int checkCipher(int);

int main(){
    int N, num, front;
    int back[4] = {1, 3, 7, 9};
    queue<int> q;
    cin >> N;
    q.push(2);
    q.push(3);
    q.push(5);
    q.push(7);
    while(1){
        num = q.front();
        if(checkCipher(num) == N){
            break;
        }
        q.pop();
        front = num * 10;
        for(int i = 0; i < 4; i++){
            if(isPrime(front+back[i])){
                q.push(front+back[i]);
            }
        }
    }
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
}

bool isPrime(int num){
    if(num % 2 == 0){
        return false;
    }
    for(int i = 3; i * i <= num; i += 2){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int checkCipher(int num){
    int result = 1;
    while(num / 10 != 0){
        num = num / 10;
        result++;
    }
    return result;
}