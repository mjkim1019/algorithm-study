#include <bits/stdc++.h>

using namespace std;

int solution(string name)
{
    int answer = 0;
    for (int i = 0; i < name.size(); i++)
        answer += min(name[i] - 'A', abs('Z' - name[i] + 1));

    // 이동 방법: 순, 역, 순역(1번 꺾기), 역순(1번 꺾기) 밖에 없음 (2번 꺾으면 절대 최소X)
    // 0에서 꺾으면 역
    int len = name.size();
    int move = len - 1;
    for (int i = 0; i < name.size(); i++)
    {
        int next = i + 1;
        while (next < len && name[next] == 'A')
            next++;
        move = min(move, i + len - next + min(len - next, i));
    }

    return answer + move;
}