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

struct cmp{
    bool operator()(mass p1,mass p2){
        if(p1.course.length()==p2.course.length())
            return p1.course > p2.course;
        else 
            return p1.course.length() < p2.course.length();
    }
};


string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "z";
    int count = k-abs(c-x)-abs(r-y);
    if(count<0 || count%2!=0)
        return "impossible";
    priority_queue<mass,vector<mass>,cmp> q;
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
    if(answer == "z") answer = "impossible";
    return answer;
}