#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;
#define ll long long

struct Pos
{
    int x, y;
    Pos() = default;
    Pos(int a, int b){
        x = a; y = b;
    }
    bool operator<(const Pos &p) const {
        if (x + y == p.x + p.y){
            if (x != p.x) return x > p.x;
            else return y > p.y;
        }
        else return (x + y) > (p.x + p.y);
    }
};

struct R
{
    Pos pos = Pos(0, 0);
    int pid, count;
    R() = default;
    R(int a, int b, int c,  int e)
    {
        pos = Pos(a, b);
        pid = c;
        count = e;
    }
    void update_pos(int a, int b)
    {
        pos = Pos(a, b);
        count++;
    }
    bool operator<(const R &r) const { 
        if (count != r.count) return count > r.count;
        if (pos.x != r.pos.x && pos.y != r.pos.y) return pos < r.pos;
        return pid > r.pid;
    }
};

int dx[4] = {-1, 0, 1, 0}; // 짝수: 상하 / 홀수: 좌우
int dy[4] = {0, -1, 0, 1};

int N, M, P;
map<int, Pos> mp; // {pid, Pos}
priority_queue<R> pq; // 최대힙
map<int, ll> score; // {pid, score}
map<int, int> dist; // {pid, dist}
vector<int> pid_v; 


void print(){
    if (pq.empty()) return;
    auto p = pq.top();
    cout << "------------------------" << '\n';
    cout << "pid = " << p.pid << '\n';
    cout << "x, y = " << p.pos.x << ", " << p.pos.y << '\n';
    cout << "count = " << p.count << '\n';
    cout << "------------------------" << '\n';
}

bool OOB(int x, int y){
    if (x < 0 || x >= N || y < 0 || y >= M) return true;
    return false;
}

Pos move(int d, int dir, int x, int y){
    if (dir %2 == 0) d %= (2*N-2); // 10억번씩 이동하면 시간초과 
    else d %= (2*M-2);
    int nx = x;
    int ny = y;
    while (d--){
        nx += dx[dir];
        ny += dy[dir];
        if (OOB(nx, ny)) {
            dir = (dir+2) % 2; // 반대방향으로 변경
            nx += dx[dir]*2; 
            ny += dy[dir]*2;
        }
    }
    return Pos(nx, ny);
}

int main()
{
    int K, S, Pit, L;
    int Q; cin >> Q;
    Q -= 2;
    int cmd;
    cin >> cmd >> N >> M >> P;
    int pid, d;
    for (int i=0; i<P; i++){
        cin >> pid >> d;
        R r = R(0, 0, pid, 0); // {x, y, pid, count}
        dist[pid] = d;
        pq.push(r);
        pid_v.push_back(pid);
    }
    while (Q--){
        cin >> cmd;
        if (cmd == 200){
            //cout << "cmd = 200" << '\n';
            cin >> K >> S;
            vector<int> selected;
            while (K--){
                //print();
                auto r = pq.top(); pq.pop();

                vector<Pos> pos_v;
                for (int dir = 0; dir<4; dir++){
                    Pos np = move(dist[r.pid], dir, r.pos.x, r.pos.y);
                    pos_v.push_back(np);
                }        
                Pos p = *min_element(pos_v.begin(), pos_v.end());
                //cout << "pos = " << p.x << ", " << p.y << '\n';
                // 다른 토끼들 점수 얻기
                for (int &id : pid_v){
                    if (id == r.pid) continue;
                    score[id] += p.x + p.y + 2;
                }
                // 결정된 토끼 다시 넣기
                r = R(p.x, p.y, r.pid, r.count+1);
                mp[r.pid] = Pos(p.x, p.y);
                pq.push(r);

                selected.push_back(r.pid);
            }
            // s 더해주기
            vector<pair<Pos, int>> pos_v;
            for (int &id: selected){
                pos_v.push_back({mp[id], id});
            }
            
            auto p = *min_element(pos_v.begin(), pos_v.end());
            //cout << "best = " << p.second << '\n';
            score[p.second] += S;
        }
        else if (cmd == 300){
            //cout << "cmd = 300" << '\n';
            cin >> Pit >> L;
            dist[Pit] *= L;
            //cout << Pit << ": " << dist[Pit] << '\n';
        } 
    }
    cin >> cmd;
    //print();
    
    ll answer = 0;
    for (int &id: pid_v){
        //cout << score[id] << ' ';
        if (answer < score[id]) answer = score[id];
    }
    //cout << '\n';
    cout << answer;

    return 0;
}