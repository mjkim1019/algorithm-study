// 구명보트
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int end = people.size();
    sort(people.begin(), people.end());
    for(int i = 0; i < end; i++){
        if(people[i] > limit / 2){
            answer++;
        }
        else{
            for(int j = end - 1; j >= i; j--){
                if(people[i] + people[j] > limit){
                    end--;
                    answer++;
                }
                else{
                    end--;
                    answer++;
                    break;
                }
            }
        }
        
    }
    return answer;
}