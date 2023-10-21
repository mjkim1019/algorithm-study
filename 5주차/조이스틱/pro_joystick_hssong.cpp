// 조이스틱
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0, flag = 0;
    int move = name.length() - 1;
    bool *visit = new bool[name.length()];
    // 이동횟수
    for(int i = 0; i < name.length(); i++){
        if(name[i] != 'A'){
            visit[i] = false;
            flag++;
        }
        else{
            visit[i] = true;
        }
    }
    if(flag == 0){
        return 0;
    }
    for(int i = 0; i < name.length(); i++){
        if(visit[i]) continue;
        int a = i;
        int b = i + 1;
        while(b < name.length() && visit[b]){
            b++;
        }
        move = min(move, a + (int)name.length() - b + min(a, (int)name.length() - b));
    }
    answer += move;
    
    
    // 알파벳 변경
    for(int i = 0; i < name.length(); i++){
        if(name[i] == 'A'){
            continue;
        }
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
    }
    return answer;
}