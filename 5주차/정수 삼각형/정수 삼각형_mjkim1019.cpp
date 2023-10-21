#include <bits/stdc++.h>
using namespace std;

int d[501][501];

int solution(vector<vector<int>> triangle)
{
    int answer = 0;

    d[0][0] = triangle[0][0];
    int height = triangle.size();
    // d[i][k] = i층에 k번째 위치에 도착했을 때 최대 합 (0부터 시작)
    for (int i = 1; i < height; i++)
    {
        d[i][0] = d[i - 1][0] + triangle[i][0];
        int last = triangle[i].size() - 1;
        d[i][last] = d[i - 1][last - 1] + triangle[i][last];
        for (int k = 1; k < triangle[i].size() - 1; k++)
        {
            d[i][k] = max(d[i - 1][k - 1], d[i - 1][k]) + triangle[i][k];
        }
    }
    answer = *max_element(d[height - 1], d[height - 1] + height);

    return answer;
}