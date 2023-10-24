// 메이즈 러너
#include<iostream>

using namespace std;

int N, M, K, result, flag;

int m[11][11];
int newm[11][11];

pair<int, int> lo[11];

int x, y, rosize;

void move();
void rotate();

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> m[i][j];
        }
    }
    int x, y;
    for(int i = 1; i <= M; i++){
        cin >> lo[i].first >> lo[i].second;
    }
    cin >> lo[0].first >> lo[0].second;

    while(K--){
        move();

        flag = 1;
        for(int i = 1; i <= M; i++){
            if(lo[i].first != lo[0].first || lo[i].second != lo[0].second){
                flag = 0;
            }
        }
        if(flag == 1){
            break;
        }
        x = 0;
        y = 0;
        rosize = 0;
        rotate();
    }

    cout << result << '\n';
    cout << lo[0].first << " " << lo[0].second;
    return 0;
}

void move(){
    for(int i = 1; i <= M; i++){
        if(lo[i].first == lo[0].first && lo[i].second == lo[0].second){
            continue;
        }
        int nx, ny;
        // 움직일 수 있는 칸이 2개 이상이라면, 상하로 움직이는 것을 우선시합니다
        // 행 우선
        if(lo[i].first != lo[0].first){
            nx = lo[i].first;
            ny = lo[i].second;
            if(nx > lo[0].first){
                nx--;
            }
            else{
                nx++;
            }
            if(m[nx][ny] == 0){
                lo[i].first = nx;
                result++;
                continue;
            }
        }

        // 열이 다른 경우
        if(lo[i].second != lo[0].second){
            nx = lo[i].first;
            ny = lo[i].second;
            if(ny > lo[0].second){
                ny--;
            }
            else{
                ny++;
            }
            if(m[nx][ny] == 0){
                lo[i].second = ny;
                result++;
                continue;
            }
        }
    }
    return;
}

void rotate(){
    int nx, ny, nsize, width, height;
    // 회전시킬 정사각형의 좌상단 좌표와 사이즈 구하기
    for(int i = 1; i <= M; i++){
        if(lo[i].first == lo[0].first && lo[i].second == lo[0].second){
            continue;
        }
        if(lo[i].first < lo[0].first){
            nx = lo[i].first;
        }
        else{
            nx = lo[0].first;
        }
        if(lo[i].second < lo[0].second){
            ny = lo[i].second;
        }
        else{
            ny = lo[0].second;
        }
        height = abs(lo[i].first - lo[0].first) + 1;
        width = abs(lo[i].second - lo[0].second) + 1;
        if(width > height){
            nx = nx - width + height;
            if(nx < 1){
                nx = 1;
            }
            nsize = width;
        }
        else{
            ny = ny - height + width;
            if(ny < 1){
                ny = 1;
            }
            nsize = height;
        }
        if(rosize == 0 || nsize <= rosize){
            if(nsize == rosize){
                if(x == 0 || nx < x){
                    x = nx;
                    y = ny;
                }
                else if(nx == x && ny < y){
                    y = ny;
                }
            }
            else{
                x = nx;
                y = ny;
            }
            rosize = nsize;
        }
    }

    // 회전시킬 정사각형 내부의 벽의 내구도 감소
    for(int i = x; i < x + rosize; i++){
        for(int j = y; j < y + rosize; j++){
            if(m[i][j] > 0){
                m[i][j]--;
            }
        }
    }

    // 정사각형 회전
    for(int i = x; i < x + rosize; i++){
        for(int j = y; j < y + rosize; j++){
            newm[x + (j - y)][y + rosize - 1 - (i - x)] = m[i][j];
        }
    }
    // 다시 옮기기
    for(int i = x; i < x + rosize; i++){
        for(int j = y; j < y + rosize; j++){
            m[i][j] = newm[i][j];
        }
    }
    // 참가자 및 출구 회전
    for(int i = 0; i <= M; i++){
        nx = lo[i].first;
        ny = lo[i].second;
        if(x <= nx && nx < x + rosize && y <= ny && ny < y + rosize){
            lo[i].first = x + (ny - y);
            lo[i].second = y + rosize - 1 - (nx - x);
        }
    }
    return;
}