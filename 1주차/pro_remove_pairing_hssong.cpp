// 짝지어 제거하기
#include <iostream>
#include<string>
#include<stack>
using namespace std;

// 스택으로 공통된 문자가 있을 시 바로 없애기
int solution(string s)
{
    int answer = -1;
    stack<char> st;
    st.push(s[0]);
    for(int i = 1; i < s.length(); i++){
        if(st.empty()){
            st.push(s[i]);
        }
        else{
            if(st.top() == s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
    }
    if(st.empty()){
        answer = 1;
    }
    else{
        answer = 0;
    }

    return answer;
}