// 다리를 지나는 트럭
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    int cur_weight = 0;
    int truck_num = truck_weights.size();
    for(int i = 0; i < truck_num; i++){
        answer++;
        if(q.size() == bridge_length){
            cur_weight -= q.front();
            q.pop();
        }
        if(cur_weight + truck_weights[i] > weight){
            q.push(0);
            i--;
        }
        else{
            cur_weight += truck_weights[i];
            q.push(truck_weights[i]);
        }
    }
    answer += bridge_length;
    return answer;
}