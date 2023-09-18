// 튜플
#include <string>
#include <vector>
#include<algorithm>
#include<sstream>

using namespace std;

int m[100001];
int n[100001];

vector<int> solution(string s) {
    vector<int> answer;
    // 문자열에서 중괄호 삭제
    s.erase(remove(s.begin(), s.end(), '{'), s.end());
    s.erase(remove(s.begin(), s.end(), '}'), s.end());

    // 문자열에서 ,를 공백으로 교체
    for(int i = 0; i < s.length(); i++){
        if(!isdigit(s[i])){
            s[i] = ' ';
        }
    }
    int num, max = 1, max_num = 1;

    // 문자열로 입력받기(공백으로 구분)
    stringstream ss(s);
    while(ss >> num){
        m[num]++;
        if(max < m[num]){
            max = m[num];
        }
        if(max_num < num){
            max_num = num;
        }
    }

    // 횟수에 따라 순서대로 n 배열에 숫자 저장
    for(int i = 1; i <= max_num; i++){
        if(m[i] != 0){
            n[m[i]] = i;
        }
    }
    // 횟수가 클수록 앞에 있는 숫자이기 때문에 역순으로 저장
    for(int i = max; i > 0; i--){
        answer.push_back(n[i]);
    }
    return answer;
}