// 입국심사
// 최솟값과 최댓값을 통한 이분 탐색
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    long long min = times.front();
    long long max = n * (long long)times.back();
    
    while(min <= max){
        long long mid = (max + min) / 2;
        long long num = 0;
        for(int i = 0; i < times.size(); i++){
            num += mid / (long long)times[i];
        }
        if(num >= n) {
            max = mid - 1;
            answer = mid;
        }
        else{
            min = mid + 1;
        }
    }
    return answer;
}