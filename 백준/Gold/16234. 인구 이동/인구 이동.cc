#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
int n,l,r,day=0;
int courties[51][51]= {0};
bool visit[51][51];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
bool flag = false;
void BFS(int y,int x){
    if(visit[y][x]) return;
    queue<pair<int,int>> q;
    vector<pair<int,int>> union_courty;
    union_courty.clear();
    int sum = courties[y][x];
    visit[y][x] = true;
    q.push({y,x});
    while (!q.empty()){
        pair<int,int> target = q.front();
        q.pop();
        union_courty.push_back(target);
        for(int i=0;i<4;i++){
            int ny = target.first + dy[i];
            int nx = target.second + dx[i];
            if(nx>=0 && ny >=0 && nx<n && ny<n && !visit[ny][nx] && abs(courties[ny][nx]-courties[target.first][target.second])<=r && abs(courties[ny][nx]-courties[target.first][target.second])>=l){
                q.push({ny,nx});
                visit[ny][nx] = true;
                sum += courties[ny][nx];
            }
        }
    }
    if(union_courty.size()>1) flag = true;
    else return;

    for(auto u : union_courty)
        courties[u.first][u.second] = sum/union_courty.size();
    
    return;
}

int main(){
    cin >> n >> l >> r;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> courties[i][j];
    do{
        flag = false;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                visit[i][j]=false;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                BFS(i,j);
        if(flag) day++;
    } while (flag);
    cout << day;
    return 0;
}