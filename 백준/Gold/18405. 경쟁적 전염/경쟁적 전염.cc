#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct virus{
    int number;
    int y;
    int x;

    virus(int number, int y, int x){
        this->number = number;
        this->x = x;
        this->y = y;
    }
    
    bool operator<(const virus& ob)const{
        return number > ob.number;
    }
};

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main(){
  int n,k,s,x,y;
  cin >> n >> k;
  vector<vector<int>> arr(n,vector<int>(n));
  vector<vector<bool>> visit(n,vector<bool>(n));
  priority_queue<virus> q;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cin >> arr[i][j];

  cin >> s >> x >> y;
  for(int i=0;i<s;i++){
    for(int it=0;it<n;it++)
        for(int cur=0; cur<n;cur++)
            if(arr[it][cur] !=0 && !visit[it][cur]){
                q.push(virus(arr[it][cur],it,cur));
                visit[it][cur] = true;
            }
    while(!q.empty()){
        virus target = q.top();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = target.x + dx[i];
            int ny = target.y + dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<n && arr[ny][nx]==0)
                arr[ny][nx] = target.number;
        }
    }
  }
  cout << arr[x-1][y-1];
}