// 스도쿠
#include<iostream>
#include<vector>

using namespace std;

int m[10][10], cnt;
vector<pair<int, int>> blank;
bool is_end = false;

void func(int);
bool check(int, int, int);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> m[i][j];
            if(m[i][j] == 0){
                cnt++;
                blank.push_back({i, j});
            }
        }
    }
    func(0);
}

void func(int n){
    if(is_end){
        return;
    }
    if(n == cnt){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout << m[i][j] << " ";
            }
            cout << '\n';
        }
        is_end = true;
        return;
    }
    for(int i = 1; i <= 9; i++){
        if(check(blank[n].first, blank[n].second, i)){
            m[blank[n].first][blank[n].second] = i;
            func(n + 1);
            m[blank[n].first][blank[n].second] = 0;
        }
    }
    return;
}

bool check(int x, int y, int num){
    for(int i = 0; i < 9; i++){
        if(m[x][i] == num || m[i][y] == num){
            return false;
        }
    }
    x = (x / 3) * 3;
    y = (y / 3) * 3;
    for(int i = x; i < x + 3; i++){
        for(int j = y; j < y + 3; j++){
            if(m[i][j] == num){
                return false;
            }
        }
    }
    return true;
}