#include <bits/stdc++.h>
#define ll long long
using namespace std;

long long solution(int n, vector<int> times)
{
    sort(times.begin(), times.end());
    ll st = 1;
    ll en = (ll)times.back() * n;
    ll answer = en;

    while (st <= en)
    {
        ll mid = (st + en) / 2;
        ll cnt = 0;
        for (auto t : times)
            cnt += mid / (ll)t;

        if (cnt >= n)
        {
            // cout << cnt << ": " << mid << '\n';
            answer = min(answer, mid);
            en = mid - 1;
        }
        else
            st = mid + 1;
    }

    return answer;
}