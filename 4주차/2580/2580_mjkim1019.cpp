#include <iostream>
#include <vector>
using namespace std;
#define X first
#define Y second

vector<pair<int, int>> blank;
int board[10][10];
bool is_found = false;

void print(){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool is_valid(int num, int x, int y){
    for (int i = 0; i < 9; i++){
        if (num == board[i][y]) return false; // 열 체크  
        if (num == board[x][i]) return false; // 행 체크
    }
    int st_x = x / 3;
    int st_y = y / 3;
    for (int i = st_x * 3; i < st_x * 3 + 3; i++){
        for (int j = st_y * 3; j < st_y * 3 + 3; j++){
            if (num == board[i][j]) return false;
        }
    }
    return true;
}

// 재귀 : n번째를 값을 구하면 n+1번째 값도 구할 수 있다
// 몇 번(L)째 빈칸의 값을 1~9 값 중 하나로 정하고 가능한지 검사하는 함수
void func(int L){
    if (blank.size() == L){
        print();
        is_found = true;
        return;
    }

    int x = blank[L].X;
    int y = blank[L].Y;
    for (int i = 1; i <= 9; i++){
        if (!is_valid(i, x, y)) continue;
        board[x][y] = i;
        func(L + 1);
        if (is_found) return;
        board[x][y] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cin >> board[i][j];
            if (board[i][j] == 0) blank.push_back({i, j});
        }
    }

    func(0);

    return 0;
}