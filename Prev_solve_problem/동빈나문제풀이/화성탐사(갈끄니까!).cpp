#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 20000000
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

struct ship{
    int x;
    int y;
    int cost;
    ship(int X, int Y, int Cost) : x(X), y(Y), cost(Cost) {}
};

void Di(int n,vector<vector<int>> &space, vector<vector<int>> &distance){
    queue<ship> q;
    q.push(ship(0,0,space[0][0]));
    distance[0][0] = space[0][0];
    while (!q.empty())
    {
        ship target = q.front();
        q.pop();
        if(distance[target.x][target.y]<target.cost) continue;
        for(int i=0;i<4;i++){
            int nx = target.x + dx[i];
            int ny = target.y + dy[i];
            if(nx>=0 && ny >=0 && nx<n && ny<n){
                if(target.cost+space[nx][ny]<distance[nx][ny]){
                    distance[nx][ny] = target.cost+space[nx][ny];
                    q.push(ship(nx,ny,distance[nx][ny]));
                }
            }
        }
    }
}

int main(){
    int T,n;
    cin >> T;
    while(T>0){
        cin >> n;
        vector<vector<int>> space(n, vector<int>(n));
        vector<vector<int>> distance(n, vector<int>(n,INF));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> space[i][j];
        Di(n,space,distance);
        for(int i=0;i<n;i++){
            space[i].clear();
            distance[i].clear();
        }
        cout << distance[n-1][n-1] << '\n';
        space.clear();
        distance.clear();
        T--;
    }


    return 0;
}