#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FALSE "FALSE"

int V;
string X;
int N;

vector<string> per(vector<char> v)
{
    vector<string> res = {};

    do
    {
        string s = "";
        if (v[0] == '0') continue;
        for (auto &e : v) s += e;
        if (V % stoi(s) != 0) continue;
        res.push_back(s);

    } while (next_permutation(v.begin(), v.end()));

    return res;
}

string select(int n)
{
    vector<int> brute(N, 1);
    fill(brute.begin(), brute.begin() + n, 0);

    // 숫자 선택
    do
    {
        vector<char> v1;
        vector<char> v2;

        for (int i = 0; i < N; i++)
        {
            if (brute[i] == 0)
                v1.push_back(X[i]);
            else
                v2.push_back(X[i]);
        }

        vector<string> g1 = per(v1);
        vector<string> g2 = per(v2);

        int a, b;
        for (string e1 : g1)
        {
            a = stoi(e1);
            b = V/a;

            if (binary_search(g2.begin(), g2.end(), to_string(b))) return X;
        }

    } while (next_permutation(brute.begin(), brute.end()));

    return FALSE;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        cin >> V;
        if (V == 0) break;
        bool found = false;
        while (!found)
        {
            X = to_string(V);
            N = X.size();
            for (int i = 1; i <= N / 2; i++)
            {
                string res = select(i);
                if (res == FALSE)
                    continue;
                cout << res << '\n';
                found = true;
                break;
            }

            if (!found) V++;
        }
    }

    return 0;
}