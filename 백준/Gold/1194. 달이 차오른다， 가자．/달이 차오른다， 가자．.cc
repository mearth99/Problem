
#include <bits/stdc++.h>


using namespace std;

struct moon{
    int y,x,count,visit;
};

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int N,M;

char arr[51][51];
int visited[51][51][1<<6];
int minv = 1e9;
int BFS(int sy, int sx){
    queue<moon> q;
    q.push({sy,sx,0,0});
    visited[sy][sx][0]=1;
    while(!q.empty()){
        moon cur = q.front();
        q.pop();
        if(arr[cur.y][cur.x]=='1') return cur.count;
        for(int i=0;i<4;i++){
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            if(ny>=0 && nx>=0 && ny<N && nx<M){
                if(visited[ny][nx][cur.visit] == 0){
                    if(arr[ny][nx]=='.' || arr[ny][nx]=='1' || arr[ny][nx]=='0'){
                        visited[ny][nx][cur.visit] = 1;
                        q.push({ny,nx,cur.count+1,cur.visit});
                    }else if('a'<= arr[ny][nx] && arr[ny][nx] <= 'f'){
                        int target_idx = cur.visit | (1 << int(arr[ny][nx] - 'a'));
                        visited[ny][nx][target_idx] = 1;
                        q.push({ny,nx,cur.count+1,target_idx});
                    }else if('A'<= arr[ny][nx] && arr[ny][nx] <= 'F'){
                        int key = cur.visit & (1 << int(arr[ny][nx]-'A'));
                        if(key!=0){
                            visited[ny][nx][cur.visit] = 1;
                            q.push({ny,nx,cur.count+1,cur.visit});
                        }
                    }
                }
            }
        }
    }
    return -1;
}


int main(){
    
    pair<int,int> start_point;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        string temp;
        cin >> temp;
        for(int j=0;j<temp.size();j++){
            arr[i][j] = temp.at(j);
            if(arr[i][j]=='0')
                start_point = {i,j};
        }
    }
    cout << BFS(start_point.first,start_point.second);
}