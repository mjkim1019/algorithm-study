#include <iostream>
using namespace std;

int p[1000001];

int get_parent(int x){
    if (p[x] < 0) return x;
    return p[x] = get_parent(p[x]);
}

bool is_diff(int a, int b){
    a = get_parent(a);
    b = get_parent(b);
    if (a == b) return false;
    else return true;
}

void make_union(int a, int b){
    if (!is_diff(a, b)) return;

    a = get_parent(a);
    b = get_parent(b);

    if (a < b) p[b] = a;
    else p[a] = b;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    fill(p,  p+N+1, -1);

    int a, b, c;
    while (M--){
        cin >> a >> b >> c;
        if (a==0){ // 합치기
            make_union(b, c);
        }else if (a==1){ // 같은 집합인지 확인
            if (!is_diff(b, c)) cout << "YES" <<'\n';
            else cout << "NO" << '\n';
        }
    }

    return 0;
}