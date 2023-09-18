#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int answer = 0;

    int N;
    cin >> N;
    vector<bool> arr(N+1, true);
    for (int i=2; i*i <= N; i++){
        for (int j=2; i*j<= N; j++){
            arr[i*j] = false;
        }
    }
    vector<int> prime_sum;
    prime_sum.push_back(0);
    for (int i=2; i<= N; i++){
        if (arr[i]){
            prime_sum.push_back(prime_sum.back()+i);
        }
    }
    
    int l=0, r=0;
    while (l<=r && r < prime_sum.size()){
        if (prime_sum[r] - prime_sum[l] < N) r++;
        else {
            if (prime_sum[r]-prime_sum[l] == N) answer++;
            l++;
        }
    }
    cout << answer;


    return 0;
}