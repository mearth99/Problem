#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int DP[501][501];
int solution(vector<vector<int>> triangle) {
    //한번 오른쪽으로 이동했다면, 왼쪽은 선택하지 못함 따라서 굳이 삼각형에 맞춰서 뭘 하지 않아도 됨.
    /*
        DP[i][j] = max(A[i][j]+DP[i-1][j],A[i][j]+DP[i-1][j-1]);
    */
    int answer = 0;
     
    DP[1][1] = triangle[0][0];
    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<triangle[i].size();j++){
            DP[i+1][j+1] =  max(triangle[i][j]+DP[i][j],triangle[i][j]+DP[i][j+1]);
        }
    }
    
    for(int i=1;i<=triangle.size();i++){
        answer = max(answer,DP[triangle.size()][i]);
    }
    
    return answer;
}