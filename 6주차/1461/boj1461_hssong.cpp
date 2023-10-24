// 도서관
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    int input, minus = 0, plus = 0, result = 0;
    vector<int> vm, vp;
    for(int i = 0; i < N; i++){
        cin >> input;
        if(input < 0){
            minus++;
            vm.push_back(-input);
        }
        else{
            plus++;
            vp.push_back(input);
        }
    }
    // 음수와 양수 절대값이 큰 순서대로 정렬
    sort(vm.begin(), vm.end(), greater<int>());
    sort(vp.begin(), vp.end(), greater<int>());
    // 음수가 없을 때
    if(minus == 0){
        result = vp[0];
        for(int i = M; i < vp.size(); i += M){
            result += vp[i] * 2;
        }
    }
    // 양수가 없을 때
    else if(plus == 0){
        result = vm[0];
        for(int i = M; i < vm.size(); i += M){
            result += vm[i] * 2;
        }
    }
    // 둘 다 있을 때는 절대값이 제일 큰 쪽은 마지막에 도달하기 위해 한 번
    // 갈 때 결과값이 제일 적으니 result에 넣은 후
    // 한 번에 들 수 있는 개수를 통해 어느 지점에서 왔다갔다 하는지 처리하기
    else{
        if(vm[0] > vp[0]){
            result = vm[0];
            for(int i = M; i < vm.size(); i += M){
                result += vm[i] * 2;
            }
            for(int i = 0; i < vp.size(); i += M){
                result += vp[i] * 2;
            }
        }
        else{
            result = vp[0];
            for(int i = M; i < vp.size(); i += M){
                result += vp[i] * 2;
            }
            for(int i = 0; i < vm.size(); i += M){
                result += vm[i] * 2;
            }
        }
    }
    cout << result;
}