#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string X;

bool vampire(int num, vector<int> & v){
    int x = stoi(X);
    if (x % num == 0){
        int num2 = x / num;
        while (num2 > 0){
            int val = num2 % 10;
            if (v[val]) v[val]--;
            else return false;
            num2 /= 10;
        }
        return true;
    } 
    return false;
}

bool check(int n){
    vector<int> brute(X.size(), 1);
    fill(brute.begin(), brute.begin()+n, 0);
    do {
        vector<int> v1;
        vector<int> v2(10);
        for (int i=0; i<X.size(); i++){
            if (brute[i] == 0) {
                v1.push_back(X[i]-'0');
            }
            else v2[X[i]-'0']++;
        }
        if (v1[0] == 0) continue;
        if (v1.size() > 1){
            do{
                int num = 0;
                int tmp = 1;
                for (int i=v1.size()-1; i >=0; i--){
                    num += tmp * v1[i];
                    tmp *=10;
                }   
                //cout << "num = " << num <<'\n';

                if (vampire(num, v2)) return true;

            }while (next_permutation(v1.begin(), v1.end()));
        } else {
            if (vampire(v1[0], v2)) return true;
        }
        
    } while (next_permutation(brute.begin(), brute.end()));

    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true){
        int N;
        cin >> N;
        if (N == 0) return 0;

        bool is_found = false;
        while (!is_found){
            X = to_string(N);
            int n = X.size() / 2;
            while (n >= 1){
                if (check(n)){
                    is_found = true;
                    break;
                }
                n--;
            }
            if (is_found) {
                cout << N << '\n';
                break;
            }
            else N++;
        }
    }

    return 0;
}