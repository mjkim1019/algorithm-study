#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    while (N--)
    {
        string str;
        cin >> str;
        sort(str.begin(), str.end());
        do{
            cout << str << '\n';
        } while (next_permutation(str.begin(), str.end()));
    }

    return 0;
}