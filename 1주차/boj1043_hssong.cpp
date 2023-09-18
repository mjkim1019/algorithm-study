// 거짓말
#include<iostream>

using namespace std;

bool know[51]; // 진실 아는 사람 번호
int check[51][51]; // 파티 온 사람 명단

int main(){
    int N, M, know_num, know_who, flag = 1;
    // 첫째 줄 입력
    cin >> N >> M;

    //둘째 줄 입력, 진실을 아는 사람 번호 체크
    cin >> know_num;
    int result = M;
    for(int i = 1; i <= know_num; i++){
        cin >> know_who;
        know[know_who] = true;
    }

    // 셋째 줄부터의 입력 
    for(int i = 1; i <= M; i++){
        cin >> check[i][0];
        for(int j = 1; j <= check[i][0]; j++){
            cin >> check[i][j];
        }
    }

    // 파티 인원 수인 check[i][0]에 진실을 말해야 될 경우
    // 0을 저장해서 구분짓는다
    // 만약 진실을 말해야 되는 사람이 있을 경우 그 파티 인원 전부에
    // 대해서 know에 true 처리를 하고 그 파티에 대한 반복을 없애기 위해
    // check[i][0]에 0을 저장하고 모든 파티를 둘러보고 다시 처음부터
    // 확인하기 위해 while문을 실행하는 flag를 1로 저장한다
    while(flag){
        flag = 0;
        for(int i = 1; i <= M; i++){
            if(check[i][0] == 0){
                continue;
            }
            else{
                for(int j = 1; j <= check[i][0]; j++){
                    if(know[check[i][j]]){
                        for(int k = 1; k <= check[i][0]; k++){
                            know[check[i][k]] = true;
                        }
                        check[i][0] = 0;
                        flag = 1;
                        break;
                    }
                }
            }
        }
    }


    // result는 위에서 파티의 수만큼 저장했으므로
    // 진실을 말해야 하는 파티를 체크하며 값을 뺀다
    for(int i = 1; i <= M; i++){
        if(check[i][0] == 0){
            result--;
        }
    }

    cout << result;

}