// 탑
#include<iostream>

using namespace std;

int m[500001];
int index[500001];

int main(){
    int N, top_index = 0;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> m[i];
    }
    // 제일 높은 탑의 몇번째 탑인지 index 배열에 저장을 한다
    // 만약 index배열에 요소가 있다면 그 요소의 탑의 높이와 현재 탑의 높이 비교
    // 현재 탑보다 높은 탑이 나올 때까지 위의 과정 반복
    // 만약 없을 시 0 출력, 있을 시 그 탑이 몇번째 탑인지 출력
    // 현재 탑이 몇번째 탑인지 index 배열에 저장(결과적으로 내림차순으로 저장됨)
    for(int i = 1; i <= N; i++){
        while(top_index != 0 && m[i] > m[index[top_index]]){
            top_index--;
        }
        if(top_index == 0){
            cout << 0 << " ";
        }
        else{
            cout << index[top_index] << " ";
        }
        index[++top_index] = i;
    }
}