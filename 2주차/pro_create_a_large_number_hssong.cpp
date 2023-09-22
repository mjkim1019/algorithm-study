// 큰 수 만들기
// 수를 제거하기 보다 큰 수를 만들어야 함으로
// 결과값의 자릿수를 구한 후
// number의 뒤에서 부터 제일 앞에까지 값을 비교하며 큰 수를 찾아서
// 결과값의 앞자리부터 구한다
// 그 다음 자리부터는 결과값에 입력한 수의 인덱스까지만 판별한다.
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    int max_index = -1, check_index;
    int num_cipher = number.length();
    int answer_cipher = num_cipher - k;
    string answer = "";
    for(int i = 0; i < answer_cipher; i++){
        char s = number[k + i];
        check_index = k + i;
        for(int j = k + i; j > max_index; j--){
            if(s <= number[j]){
                s = number[j];
                check_index = j;
            }
        }
        answer += s;
        max_index = check_index;
    }
    return answer;
}