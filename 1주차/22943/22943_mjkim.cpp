#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<bool> prime(100000, true);
vector<bool> res(100000, false);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int answer = 0;

    int K, M;
    cin >> K >> M;
    // 1. 숫자 만들기
    vector<int> arr;
    vector<int> brute(10, 1);
    fill(brute.begin(), brute.begin()+K, 0);
    do {
        vector<int> select;
        for (int i=0; i<10; i++) if (brute[i] == 0) select.push_back(i);

        do{
            string s = "";
            if (select[0] == 0) continue;
            for (int i=0; i<K; i++){
                s += select[i] + '0';
            }
            //cout << s << '\n';
            arr.push_back(stoi(s));
        }while (next_permutation(select.begin(), select.end()));
    } while (next_permutation(brute.begin(), brute.end()));

    // 2. 소수 찾기
    sort(arr.begin(), arr.end());

    prime[0] = false; prime[1] = false;
    for (int i=2; i*i <= arr.back(); i++){
        if (prime[i] == false) continue;
        for (int j=2; i*j <=arr.back(); j++){
            prime[i*j] = false;
        }
    }
    vector<int> prime_num;
    for (int i=2; i<= arr.back(); i++){
        if (prime[i]) prime_num.push_back(i); // 정렬된 상태로 들어감
    }

    // 3. 조건 1
    for (int i=0; i<prime_num.size()-1; i++){
        for (int j=i+1; j<prime_num.size(); j++){
            int num = prime_num[i] + prime_num[j];
            if (binary_search(arr.begin(), arr.end(), num)) res[num] = true;
        }
    }

    // 4. 조건 2
    for (int &n: arr){
        int tmp = n;
        while (tmp%M == 0) tmp /= M;
        for (int &p: prime_num) {
            if (tmp <= p) break;
            if (tmp % p != 0) continue;
            if (binary_search(prime_num.begin(), prime_num.end(), tmp/p)){
                if (res[n]) answer++;
                break;
            }
        }
    }
    cout << answer;


    return 0;
}