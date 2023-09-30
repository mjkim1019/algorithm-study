// 애너그램
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int len;

void dfs(string, int);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    string s;
    vector<string> v;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s;
        v.push_back(s);
    }

    for(int i = 0; i < N; i++){
        s = v[i];
        len = s.length();
        sort(s.begin(), s.end());
        dfs(s, 0);
    }
}

void dfs(string str, int idx){
    if(idx == len - 1){
        cout << str << '\n';
        return;
    }
    for(int i = idx; i < len; i++){
        if(i != idx && str[i] == str[idx]){
            continue;
        }
        if(str[i] != str[idx]){
            char temp = str[i];
            str[i] = str[idx];
            str[idx] = temp;
        }
        dfs(str, idx+1);
    }
}