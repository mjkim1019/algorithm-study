// 정수 삼각형
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int depth = triangle.size();
    for(int i = depth - 1; i > 0; i--){
        for(int j = 0; j < triangle[i].size() - 1; j++){
            if(triangle[i][j] > triangle[i][j + 1]){
                triangle[i - 1][j] += triangle[i][j];
            }
            else{
                triangle[i - 1][j] += triangle[i][j + 1];
            }
        }
    }
    answer = triangle[0][0];
    return answer;
}