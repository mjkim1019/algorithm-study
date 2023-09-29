#include <iostream>
#include <vector>
using namespace std;

int board[10][10];

bool check_raw(int k){
    vector<bool> num(10, false);
    vector<int> v;
    for (int i=0; i<9; i++){
        if (board[i][k] == 0) v.push_back(i);
        else num[board[i][k]] = true;
    }
    if (v.size() == 0) return true;
    else if (v.size() > 1) return false;
    for (int i=1; i<=9; i++) {
        if (num[i] == false) {
            board[v[0]][k] = i;
        }
    }
    return true;
}

bool check_col(int k){
    vector<bool> num(10, false);
    vector<int> v;
    for (int j=0; j<9; j++){
        if (board[k][j] == 0) v.push_back(j);
        else num[board[k][j]] = true;
    }
    //cout << k <<"행 : "<< cnt << '\n';
    if (v.size() == 0) return true;
    else if (v.size() > 1) return false;
    for (int i = 1; i <= 9; i++){
        if (num[i] == false) {
            board[k][v[0]] = i;
        }
    }
    return true;
}

bool check_square(int x, int y){
    vector<pair<int, int>> v;
    vector<bool> num(10, false);
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (board[x+i][y+j] == 0) v.push_back({x+i, y+j});
            else num[board[x+i][y+j]] = true;
        }
    }
    if (v.size() == 0) return true;
    else if (v.size() > 1) return false;
    for (int i = 1; i <= 9; i++){
        if (num[i] == false) {
            board[v[0].first][v[0].second] = i;
        }
    }
    return true;
}

void print(){
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i=0; i<9; i++)
        for (int j=0; j<9; j++)
            cin >> board[i][j];
    //cout << "----------------------" << '\n';

    bool col, raw, square;
    while(true){
        col = raw = square = true;
        for (int i=0; i<9; i++) if (!check_col(i)) col = false; 
        for (int j=0; j<9; j++) if (!check_raw(j)) raw = false;
        for (int i=0; i<=6; i+=3){
            for (int j=0; j<=6; j+=3){
                if (!check_square(i, j)) square = false;
            }
        }
        if (col && raw && square) break;
        // print();
        // cout << "----------------------"<<'\n';
    }
    print();

    return 0;
}