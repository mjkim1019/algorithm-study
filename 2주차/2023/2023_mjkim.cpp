#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;

bool is_prime(int num){
    if (num<2) return false;
    
    for (int i=2; i*i <= num; i++){
        if (num % i == 0) return false;
    }
    return true;
}

void dfs(int L, string num){
    if (L == N){
        if (is_prime(stoi(num)))
            cout << num << '\n';
        return;
    }

    for (int i=0; i<=9; i++){
        if (L==0 && i==0) continue;
        string str = num + to_string(i);
        if (is_prime(stoi(str))) dfs(L+1, str);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    dfs(0, "");
    
    return 0;
}