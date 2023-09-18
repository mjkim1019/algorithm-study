// 뱀파이어 숫자
#include<iostream>
#include<string>
#include<queue>

using namespace std;

bool IsVampireNum(int);
int GetVampireNum(int);

int main(){
    int X;
    queue<int> q;
    while(1){
        cin >> X;
        if(X == 0){
            break;
        }
        if(X <= 126){
            q.push(126);
        }
        else{
            q.push(GetVampireNum(X));
        }
    }
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
}

bool IsVampireNum(int num){
    string a, b;
    string c;
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0){
            a = to_string(num / i);
            b = to_string(i);
            c = to_string(num);
            if(c.length() != a.length() + b.length()){
                continue;
            }
            else{
                for(int i = 0; i < a.length(); i++){
                    for(int j = 0; j < c.length(); j++){
                        if(c[j] == a[i]){
                            c.erase(c.begin() + j);
                            break;
                        }
                    }
                }
                for(int i = 0; i < b.length(); i++){
                    for(int j = 0; j < c.length(); j++){
                        if(c[j] == b[i]){
                            c.erase(c.begin() + j);
                            break;
                        }
                    }
                }
                if(c == ""){
                    return true;
                }
            }
        }
    }
    return false;
}

int GetVampireNum(int num){
    while(!IsVampireNum(num)){
        num++;
    }
    return num;
}