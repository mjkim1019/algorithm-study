// 문자열 폭발
#include<iostream>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string original_s, explosion_s, stack_s;
    cin >> original_s;
    cin >> explosion_s;
    for(int i = 0; i < original_s.length(); i++){
        stack_s += original_s[i];
        if(stack_s.length() >= explosion_s.length()){
            for(int j = 0; j < explosion_s.length(); j++){
                if(stack_s[stack_s.length() - explosion_s.length() + j] != explosion_s[j]){
                    break;
                }
                if(j == explosion_s.length() - 1){
                    stack_s.erase(stack_s.end() - explosion_s.length(), stack_s.end());
                }
            }
        }
    }
    if(stack_s.empty()){
        cout << "FRULA" << '\n';
    }
    else{
        cout << stack_s << '\n';
    }
}