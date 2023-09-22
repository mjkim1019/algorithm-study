// 집합의 표현
// 입출력 시간 때문에 시간 초과가 많이 발생해서
// 입출력에 신경써야 하며 endl은 개행문자보다 시간 소요가 크다
#include<iostream>

using namespace std;

int s[1000001];
bool result[100001];
int index = 0;

void func(int, int, int);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, s, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> s >> a >> b;
        func(s, a, b);
    }
    for(int i = 0; i < index; i++){
        if(result[i]){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
}

void func(int state, int a, int b){
    // 합집합 - 작은 숫자가 큰 숫자를 부모로 삼는다
    // 최상단 부모까지 올라가서 두 수를 비교해 루트가 다르면
    // 합집합 연결을 한다
    if(state == 0){
        if(a == b) return;
        int x = a, y = b;
        for(; s[x] != 0; x = s[x]){
        }
        for(; s[y] != 0; y = s[y]){
        }
        if(x != y){
            if(x > y){
                s[y] = x;
            }
            else{
                s[x] = y;
            }
        }
    }
    // 같은 집합인지 판별
    // 각자의 루트가 같은지 비교하고 그에 대한 결과를 저장한다
    else if(state == 1){
        if(a == b){
            result[index++] = true;
        }
        else{
            int x = a, y = b;
            for(; s[x] != 0; x = s[x]){
            }
            for(; s[y] != 0; y = s[y]){
            }
            if(x == y){
                result[index++] = true;
            }
            else{
                result[index++] = false;
            }
        }
    }
}