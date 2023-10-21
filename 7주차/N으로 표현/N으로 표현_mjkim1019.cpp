#include <bits/stdc++.h>
using namespace std;

set<int> d[10];

int solution(int N, int number)
{
    int tmp = 0;
    for (int i = 1; i <= 8; i++)
    {
        tmp = tmp * 10 + N;
        if (tmp == number) return i;
        d[i].insert(tmp);
    }

    for (int k = 2; k <= 8; k++)
    {
        for (int i = 1; i < k; i++)
        {
            for (int a : d[i])
            {
                for (int b : d[k - i])
                {
                    if (a + b == number || a - b == number || a * b == number || (b != 0) && a / b == number)
                        return k;
                    d[k].insert(a + b);
                    d[k].insert(a - b);
                    d[k].insert(a * b);
                    if (b != 0) d[k].insert(a / b);
                }
            }
        }
    }

    return -1;
}