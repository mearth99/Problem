#include <vector>

using namespace std;

int MOD = 20170805;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    vector<vector<vector<long long>>> DP(m+1, vector<vector<long long>>(n+1, vector<long long> (2)));
    for(int i=0;i<m;i++){
        if(city_map[i][0]==1)
            break;
        DP[i][0][0] = 1; 
    }
    for(int i=0;i<n;i++){
        if(city_map[0][i]==1)
            break;
        DP[0][i][1] = 1;
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
                //위쪽길이 프리한 경우.
            if(city_map[i-1][j]==0){
                DP[i][j][0] += (DP[i-1][j][0]+DP[i-1][j][1])%MOD; //i의 위에서 오는 값은 i-1의 위에서 온 값 + i-1의 왼쪽에서 온 값 
            }
            if(city_map[i-1][j]==2){
                //위쪽길에 방향전환 금지인 경우
                DP[i][j][0] += (DP[i-1][j][0]%MOD); //i의 위에서 오는 값은 i-1의 위에서 온 값 
            } 
                //왼쪽길이 프리한 경우
            if(city_map[i][j-1]==0){
                DP[i][j][1] += (DP[i][j-1][0]+DP[i][j-1][1])%MOD; //i의 왼쪽에서 오는 값은 j-1의 위에서 온 값 + j-1의 왼쪽에서 온 값 
            }
            if(city_map[i][j-1]==2){
                //왼쪽길이 방향전환 금지인 경우
                DP[i][j][1] += (DP[i][j-1][1]%MOD);
            }
        }
    }
    int answer = (DP[m-1][n-1][0]+DP[m-1][n-1][1])%MOD;
    return answer;
}