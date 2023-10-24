#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--){
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    bool is_valid = true;
    for (int i=1; i<n; i++){
        if (arr[i-1].size() < arr[i].size()){
            if (arr[i].substr(0, arr[i-1].size()) == arr[i-1]) {
                is_valid = false; break;
            }
        }
    }
    if (is_valid) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    }


    return 0;
}