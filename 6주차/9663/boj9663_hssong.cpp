// N-Queen
#include<iostream>

using namespace std;

int N, result;
int queen[15];

void func(int);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    func(0);
    cout << result;
}

void func(int row){
    if(row == N){
        result++;
        return;
    }
    for(int i = 0; i < N; i++){
        queen[row] = i;
        int flag = 1;
        for(int j = 0; j < row; j++){
            if(queen[j] == queen[row] || abs(queen[j] - queen[row]) == row - j){
                flag = 0;
            }
        }
        if(flag == 1){
            func(row + 1);
        }
    }
}