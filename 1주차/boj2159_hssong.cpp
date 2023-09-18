// 케익 배달
#include<iostream>

using namespace std;

int N;
int X[100001];
int Y[100001];

void ChangeLocation(int);
int GetDistance(int);

int main(){
    long long result = 0;
    cin >> N;
    for(int i = 0; i <= N; i++){
        cin >> X[i] >> Y[i];
    }
    for(int i = 0; i < N - 1; i++){
        ChangeLocation(i);
        result += GetDistance(i);
    }
    // 마지막은 두 거리에서 1을 빼면 최소거리이기 때문에 이렇게 처리함(겹쳐있을 때 제외)
    result += GetDistance(N-1);
    if(GetDistance(N-1) != 0){
        result--;
    }
    cout << result;
}

// 현재랑 다다음거 네모 해서 다음 것이 어느 위치에 있는지 확인하여 최소거리로 갈 수 있는 위치로 조정하는 함수
void ChangeLocation(int index){
    if(Y[index+1] > Y[index] && Y[index+1] > Y[index+2]){ // 위에 있는 경우
        Y[index+1]--;
    }
    else if(Y[index+1] < Y[index] && Y[index+1] < Y[index+2]){ // 아래에 있는 경우
        Y[index+1]++;
    }
    else{ // 경계선 또는 사이에 있는 경우
        if(X[index+1] > X[index] && X[index+1] > X[index+2]){ // 오른쪽에 있는 경우
            X[index+1]--;
        }
        else if(X[index+1] < X[index] && X[index+1] < X[index+2]){ // 왼쪽에 있는 경우
            X[index+1]++;
        }
    }
}

// 현재 위치와 다음 위치의 거리를 구해서 반환하는 함수
int GetDistance(int index){
    int x, y;
    x = X[index] - X[index+1];
    y = Y[index] - Y[index+1];
    if(x < 0) x = -x;
    if(y < 0) y = -y;
    return x + y;
}