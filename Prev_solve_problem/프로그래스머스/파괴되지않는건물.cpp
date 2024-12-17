#include <string>
#include <vector>
#include <iostream>
using namespace std;
void attack(vector<vector<int>> &sum, vector<int> detail){
  int type = detail[0], y1 = detail[1], y2 = detail[3], x1 = detail[2], x2 = detail[4], degree = detail[5];
  if(type==1)
    degree*=-1;
  sum[y1][x1] += degree;
  sum[y1][x2+1] -= degree;
  sum[y2+1][x1] -= degree;
  sum[y2+1][x2+1] += degree;
}
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int row = board.size();
    int col = board[0].size();
    vector<vector<int>> sum(row+1, vector<int>(col+1));
    int answer = 0;
    for(auto idx:skill){
      attack(sum,idx);
    }
    for(int i=1;i<row;i++){
      for(int j=0;j<col;j++){
       sum[i][j] += sum[i-1][j]; 
      }
    }
    for(int i=0;i<row;i++){
      for(int j=1;j<col;j++){
       sum[i][j] += sum[i][j-1]; 
      }
    }
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            if(board[i][j]+sum[i][j]>0)
                answer++;
    
    return answer;
}