#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dx[] = {-1,1,0,0}; //좌우상하.
int dy[] = {0,0,1,-1};
int answer = 999999999;
int cost4dir[25][25][4];
void DFS(int x, int y, vector<vector<int>>& board, int costs,int predirection){
    int size = board.size()-1;
    if(costs>answer) return;
    if(x==size&&y==size){
        answer = min(answer,costs);
        return;
    }
    for(int i=0;i<4;i++){
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (ny < 0 || ny > size || nx < 0 || nx > size || board[ny][nx] == 1)
            continue;
        int nextcosts = costs+100;
        if(predirection!=-1 && i!=predirection&&i+predirection!=1 && i+predirection!=5)
            nextcosts+=500;
        if(cost4dir[ny][nx][i]>nextcosts){
            cost4dir[ny][nx][i] = nextcosts;
            DFS(nx,ny,board,nextcosts,i);
        }
    }
}
int solution(vector<vector<int>> board) {
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            for(int k=0;k<4;k++)
                cost4dir[i][j][k] = 999999;
        }
    }
    DFS(0,0,board,0,-1);
    return answer;
}