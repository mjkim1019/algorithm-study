#include <iostream>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--){
    int K; cin >> K;
    multiset<int> s;
    while (K--){
        char c;
        int n;
        cin >> c >> n;
        if (c == 'I') {
            s.insert(n);
        }
        if (c == 'D'){
            if (s.empty()) continue;
            if (n == 1){ // 최댓값 삭제
                s.erase(prev(s.end()));                
            } else { // 최솟값 삭제
                s.erase(s.begin());
            }
        }
    }

    if (s.empty()){
        cout << "EMPTY" << '\n';
    } else {
        cout << *prev(s.end()) << ' ' << *s.begin() << '\n';
    }
    }

    return 0;
}