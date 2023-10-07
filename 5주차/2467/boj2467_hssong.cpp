// 용액
#include<iostream>

using namespace std;

int N, l, r, min_value, min_left, min_right;
int m[100001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> m[i];
    }
    l = 0;
    r = N - 1;
    min_left = m[l];
    min_right = m[r];
    min_value = abs(min_left + min_right);

    while(l < r){
        int temp = m[l] + m[r];
        if(abs(temp) < min_value){
            min_value = abs(temp);
            min_left = m[l];
            min_right = m[r];
        }
        if(temp < 0){
            l++;
        }
        else{
            r--;
        }
    }

    cout << min_left << " " << min_right;
    
}