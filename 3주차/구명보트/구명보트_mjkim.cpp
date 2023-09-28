#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit){
    sort(people.begin(), people.end());
    int r = 0;
    int l = people.size() - 1;
    int cnt = 0;
    while (r < l){
        if (people[r] + people[l] <= limit){
            cnt++;
            r++; l--;
        }
        else l--;
        
    }

    return people.size() - cnt;
}