#include <bits/stdc++.h>

using namespace std;

int arr[100001];

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.first > b.first;
}

vector<int> solution(string s)
{
    vector<int> answer;

    for (int i = 0; i < s.size(); i++)
    {
        if (!isdigit(s[i]))
            s[i] = ' ';
    }

    stringstream ss(s);
    int num;
    while (ss >> num)
    {
        arr[num]++;
    }

    vector<pair<int, int>> v; // {횟수, 숫자}
    for (int i = 0; i < 100001; i++)
    {
        if (arr[i] == 0)
            continue;
        v.push_back({arr[i], i});
    }
    sort(v.begin(), v.end(), cmp);
    for (auto &i : v)
        answer.push_back(i.second);

    return answer;
}