#include<vector>
#include<algorithm>
using namespace std;
int dx[4]={0,0,1,-1}; //상하좌우
int dy[4]={-1,1,0,0};
int answer = 9999999;
void dfs(int x, int y, int count, vector<vector<int>> maps){
    if(x==maps[0].size()-1&&y==maps.size()-1){
        answer = min(answer,count);
        return;
    }
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0<=nx&&nx<maps[0].size()&&0<=ny&&ny<maps.size())
        {
            if(maps[ny][nx]==0)
                continue;
            maps[ny][nx] = 0;
            dfs(nx,ny,count+1,maps);
            maps[ny][nx] = 1;
        }
    }
}
int solution(vector<vector<int>> maps)
{
    dfs(0,0,1,maps);
    if(answer==9999999)
        return -1;
    return answer;
}