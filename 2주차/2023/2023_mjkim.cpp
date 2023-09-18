#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;

vector<bool> prime(1000000000, true);

void dfs(int L, string num){
    if (L == N){
        if (prime[stoi(num)])
            cout << num << '\n';
        return;
    }

    for (int i=0; i<=9; i++){
        if (L==0 && i==0) continue;
        string str = num + to_string(i);
        if (prime[stoi(str)]) dfs(L+1, str);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    prime[0] = false; prime[1] = false;
    for (int i=2; i*i<pow(10, N); i++){
        if (prime[i] == false) continue;
        for (int j=2; i*j<pow(10, N); j++){
            prime[i*j] = false;
        }
    }
    
    dfs(0, "");
    
    return 0;
}