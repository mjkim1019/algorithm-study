// 주사위 굴리기
// vector를 이용하여 주사위가 이동했을 때 주사위의 각 면의 위치가
// 어떤 식으로 바뀌었는지 판단 후 변경을 했다
#include<iostream>
#include<vector>

using namespace std;

int m[20][20];
int k[1000];
vector<int> dice(6);
// 동쪽(x+1)은 1, 서쪽(x-1)은 2, 북쪽(y-1)은 3, 남쪽(y+1)은 4

void east();
void west();
void north();
void south();

int main(){
    int N, M, x, y, K;
    cin >> N >> M >> y >> x >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> m[i][j];
        }
    }
    for(int i = 0; i < K; i++){
        cin >> k[i];
    }
    for(int i = 0; i < K; i++){
        if(k[i] == 1){
            if(x + 1 >= M){
                continue;
            }
            else{
                x += 1;
                east();
            }
        }
        else if(k[i] == 2){
            if(x - 1 < 0){
                continue;
            }
            else{
                x -= 1;
                west();
            }
        }
        else if(k[i] == 3){
            if(y - 1 < 0){
                continue;
            }
            else{
                y -= 1;
                north();
            }
        }
        else if(k[i] == 4){
            if(y + 1 >= N){
                continue;
            }
            else{
                y += 1;
                south();
            }
        }
        cout << dice[0] << endl;
        if(m[y][x] == 0){
            m[y][x] = dice[5];
        }
        else{
            dice[5] = m[y][x];
            m[y][x] = 0;
        }
    }
}

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