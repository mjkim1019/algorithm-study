#include <bits/stdc++.h>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int w = 0;
    queue<int> Q;
    int i = 0;
    while (i < truck_weights.size())
    {
        int truck = truck_weights[i];
        answer++;
        if (Q.size() == bridge_length)
        {
            w -= Q.front();
            Q.pop();
        }
        if (w + truck <= weight)
        {
            Q.push(truck);
            w += truck;
            i++;
        }
        else
        {
            if (Q.size() < bridge_length)
                Q.push(0);
        }
    }

    answer += bridge_length; // 마지막 트럭이 올라탄 후에 반복문이 끝나므로

    return answer;
}