#include <iostream>
#include <vector>
using namespace std;

int board[25][25];
int N, M, x, y;

// 동, 서, 북, 남
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

vector<int> dice(6);

void east(){
    dice = {dice[3], dice[1], dice[0], dice[5], dice[4], dice[2]};
}

void west(){
    dice = {dice[2], dice[1], dice[5], dice[0], dice[4], dice[3]};
}

void north(){
    dice = {dice[4], dice[0], dice[2], dice[3], dice[5], dice[1]};
}

void south(){
    dice = {dice[1], dice[5], dice[2], dice[3], dice[0], dice[4]};
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K;
    cin >> N >> M >> x >> y >> K;

    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            cin >> board[i][j];
    
    while (K--){
        int dir;
        cin >> dir;
        int nx = dx[dir] + x;
        int ny = dy[dir] + y;
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

        if (dir == 1) east();
        else if (dir == 2) west();
        else if (dir == 3) north();
        else if (dir == 4) south();

        if (board[nx][ny] == 0) board[nx][ny] = dice[5];
        else {
            dice[5] = board[nx][ny];
            board[nx][ny] = 0;
        }

        cout << dice[0] << '\n';

        x = nx;
        y = ny;
    }


    return 0;
}