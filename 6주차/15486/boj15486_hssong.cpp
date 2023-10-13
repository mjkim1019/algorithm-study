// 퇴사2
#include<iostream>

using namespace std;

int N, result, now;
int DP[1500001];
int TP[1500001][2];

void func(int, int, int);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> TP[i][0] >> TP[i][1];
        func(i, TP[i][0], TP[i][1]);
    }
    cout << result;
}

void func(int index, int t, int p){
    int newp, oldp;
    if(now > DP[index]){
        DP[index] = now;
    }
    else if(now < DP[index]){
        now = DP[index];
    }
    if(index + t > N){
        return;
    }
    newp = DP[index] + p;
    oldp = DP[index + t];
    if(newp > oldp){
        DP[index + t] = newp;
        if(newp > result){
            result = newp;
        }
    }
    return;
}