#include <iostream>
#include <vector>
using namespace std;

bool check(string n){
    for (int i=1; i<n.size(); i++){
        if (n[i-1] <= n[i]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    if (N<=10) {
        cout << N; return 0;
    }

    vector<int> v;
    for (int i=0; i<=10; i++) v.push_back(i);

    int num = 20;
    while(v.size() != N){
        
        if (check(to_string(num))) {
            v.push_back(num);
        }
        num++;

        if (v.size() == N+1) {
            cout << v.back(); 
            return 0;
        }

        if (num > 9876543210) {
            cout << "-1"; return 0;
        }
    }


    return 0;
}