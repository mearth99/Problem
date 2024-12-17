#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int dx[4]={0,0,1,-1}; //상하좌우
int dy[4]={-1,1,0,0};
int answer = 9999999;
struct three{
    int x;
    int y;
    int count;
};
queue<three> q; 
three make_three(int x,int y,int count){
    three temp;
    temp.x = x; temp.y = y; temp.count = count;
    return temp;
}
int solution(vector<vector<int>> maps)
{
    q.push(make_three(0,0,1));
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int count = q.front().count;
        q.pop();
        if(x==maps[0].size()-1&&y==maps.size()-1){
            answer = min(answer,count);
            continue;
        }
        for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
            if(0<=nx&&nx<maps[0].size()&&0<=ny&&ny<maps.size()){
                if(maps[ny][nx]==0)
                    continue;
                maps[ny][nx] = 0;

                q.push(make_three(nx,ny,count+1));
            }
        }
    }
    if(answer==9999999)
        return -1;
    return answer;
}