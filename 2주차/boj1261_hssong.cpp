// 알고스팟
// 배열의 크기를 101로 했었는데 사용하는 공간이 1 ~ 100 index이지만
// 코드 상 접근은 101번째 index도 하기 때문에 에러가 발생하여 배열의
// 크기를 1 더 키워주었다
#include<iostream>
#include<queue>

using namespace std;

int maze[102][102];
bool visited[102][102];

struct Compare {
    bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b){
        if(a.first == b.first){
            if(a.second.first == b.second.first){
                return a.second.second < b.second.second;
            }
            return a.second.first < b.second.first;
        }
        return a.first > b.first;
    }
};

void fun(int, int);

int main(){
    int N, M;
    cin >> M >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            scanf("%1d", &maze[i][j]);
        }
    }
    fun(N, M);
}

// num은 벽을 부순 횟수로 오름차순
// x, y는 N, M으로 가야 되기 때문에 내림차순으로 우선순위 큐를 구현했다
void fun(int N, int M){
    int x = 1, y = 1, num = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> q;
    q.push({num, {x, y}});
    visited[x][y] = true;
    while(!q.empty()){
        num = q.top().first;
        x = q.top().second.first;
        y = q.top().second.second;
        q.pop();
        if(x == N && y == M){
            break;
        }
        if(!visited[x+1][y] && x+1 <= N){
            q.push({num+maze[x+1][y],{x+1, y}});
            visited[x+1][y] = true;
        }
        if(!visited[x][y+1] && y+1 <= M){
            q.push({num+maze[x][y+1],{x, y+1}});
            visited[x][y+1] = true;
        }
        if(!visited[x-1][y] && x-1 >= 1){
            q.push({num+maze[x-1][y],{x-1, y}});
            visited[x-1][y] = true;
        }
        if(!visited[x][y-1] && y-1 >= 1){
            q.push({num+maze[x][y-1],{x, y-1}});
            visited[x][y-1] = true;
        }
    }
    cout << num << endl;
}