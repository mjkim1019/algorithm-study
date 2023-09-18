#include <iostream>
#include <algorithm>
using namespace std;

bool is_vampire(int V)
{
    string origin = to_string(V);
    sort(origin.begin(), origin.end());
    string vampire = "";
    for (int i = 2; i * i <= V; i++)
    {
        if (V % i != 0) continue;

        vampire = to_string(i) + to_string(V / i);
        sort(vampire.begin(), vampire.end());

        if (origin == vampire) return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        int X;
        cin >> X;
        if (X == 0) break;
        while (!is_vampire(X)) X++;
        cout << X << '\n';
    }

    return 0;
}