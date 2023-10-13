// 전화번호 목록
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int t, n, result[51];

void input(int);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for(int i = 0; i < t; i++){
        input(i);
    }
    for(int i = 0; i < t; i++){
        if(result[i] == 1){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
}

void input(int t){
    vector<string> v;
    string s;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    for(int i = 1; i < n; i++){
        for(int j = 0; j < v[i - 1].length(); j++){
            if(v[i - 1][j] != v[i][j]){
                break;
            }
            if(j == v[i - 1].length() - 1){
                result[t] = 1;
                return;
            }
        }
    }
}