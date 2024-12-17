#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
int dx[4] = {0,-1,1,0};
int dy[4] = {1,0,0,-1};
char route[4] = {'d','l','r','u'};

struct mass{
    int x;
    int y;
    string course;
};

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    if(k-abs(c-x)+abs(r-y)<0 || k-abs(c-x)+abs(r-y)%2!=0)
        return "impossible";
    priority_queue<mass> q;
    q.push({y,x,""});
    while(!q.empty()){
        int cx = q.top().x;
        int cy = q.top().y;
        string course = q.top().course;
        q.pop();
        if(course.length()==k && cx==c && cy ==r){
            answer = course;
            return answer;
        }else{
            int distan = k - course.length();
            if(distan < abs(c-cx)+abs(r-cy)) continue;
            for(int i=0;i<4;i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(nx>=1&&ny>=1&&nx<=m&&ny<=n){
                    q.push({nx,ny,course+route[i]});
                }
            }
        }
    }
    if(answer == "") answer = "impossible";
    return answer;
}