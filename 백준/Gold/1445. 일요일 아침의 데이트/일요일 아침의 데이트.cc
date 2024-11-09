#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 2000000
using namespace std;


int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

struct load{
    int x;
    int y;
    int waste;
    int near_waste;
    load(int y, int x, int w, int near){
        this->x = x;
        this->y = y;
        this->waste = w;
        this->near_waste = near;
    }
};
struct cmp{
    bool operator()(load p1, load p2){
        if(p1.waste==p2.waste)
            return p1.near_waste > p2.near_waste;
        else 
            return p1.waste > p2.waste;
    }
};

bool visited[52][52];
int forest[52][52];
int minwaste = 0;
int min_near_waste = 0;

void Dijk(int n, int m, pair<int,int> start, pair<int,int> end){
    priority_queue<load, vector<load>, cmp> q;
            
    q.push(load(start.first, start.second,0,0));
    visited[start.first][start.second] = true;

    while(!q.empty()){
        load target = q.top(); q.pop();
        for(int i=0;i<4;i++){
            int nx = target.x + dx[i];
            int ny = target.y + dy[i];
            if(ny==end.first&&nx==end.second){
                minwaste = target.waste;
                min_near_waste = target.near_waste;
                return;
            }
            if(nx>=0 && nx<m && ny>=0 && ny<n && !visited[ny][nx]){
                int cur_waste = target.waste + (forest[ny][nx]==2 ? 1 : 0);
                int cur_near_waste = target.near_waste + (forest[ny][nx]==2 ? 0 : forest[ny][nx]);
                q.push(load(ny,nx,cur_waste,cur_near_waste));
                visited[ny][nx] = true;
            }
        }
    }  
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    
    pair<int,int> start; //y,x
    pair<int,int> end;

    for(int i=0;i<52;i++)
        for(int j=0;j<52;j++)
            visited[i][j] = false;

    for(int i=0;i<n;i++){
        string temp;
        cin >> temp;
        for(int j=0;j<temp.length();j++){
            if(temp.at(j)=='S'){
                start.first = i;
                start.second = j;
            }else if(temp.at(j)=='F'){
                end.first = i;
                end.second = j;
            }else if(temp.at(j)=='g'){
                forest[i][j]=2;
                for(int k=0;k<4;k++){
                    int nx = dx[k] + j;
                    int ny = dy[k] + i;
                    if(nx>=0&&nx<m&&ny>=0&&ny<n){
                        if(forest[ny][nx]!=2)
                            forest[ny][nx] = 1;
                    }
                }
            }
        }
    }
    Dijk(n,m,start,end);
    cout << minwaste << " " << min_near_waste;
    return 0;
}