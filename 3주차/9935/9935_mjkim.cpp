#include <iostream>
#include <deque>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str; 
    cin >> str;
    string bomb;
    cin >> bomb;

    deque<char> S;
    for (int i=0; i<str.size(); i++){
        S.push_back(str[i]);
        bool is_valid = true;
        stack<char> tmp;
        int k = bomb.size()-1;
        while (k >= 0 && !S.empty())
        {
            if (S.back() != bomb[k]){
                is_valid = false; break;
            } else {
                k--; 
                tmp.push(S.back());
                S.pop_back();
            }
        }
        if (!is_valid || k>=0){
            while (!tmp.empty()){
                S.push_back(tmp.top());
                tmp.pop();
            }
        }


    }

    if (S.empty()) {
        cout << "FRULA"; return 0;
    }
    while (!S.empty()){
        cout << S.front();
        S.pop_front();
    }

    return 0;
}