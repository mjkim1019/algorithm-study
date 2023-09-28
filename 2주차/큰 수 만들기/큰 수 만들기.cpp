#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k)
{
    string answer = "";

    stack<char> S;
    int cnt = 0;
    for (int i = 0; i < number.size(); i++)
    {
        while (cnt < k && !S.empty() && S.top() < number[i])
        {
            S.pop();
            cnt++;
            if (cnt == k)
                break;
        }
        S.push(number[i]);
    }
    while (cnt < k)
    {
        S.pop();
        cnt++;
    }
    while (!S.empty())
    {
        answer += S.top();
        S.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}