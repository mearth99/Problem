#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
vector<pair<int,int>> teacher;
bool flag = false;
bool teacher_monitor(vector<vector<char>> &school){
    for(auto it : teacher){
        for(int j=it.second-1;j>=0;j--)
            if(school[it.first][j]=='S') return true;
            else if(school[it.first][j]=='O') break;
        for(int j=it.second;j<school.size();j++)
            if(school[it.first][j]=='S') return true;
            else if(school[it.first][j]=='O') break;
        for(int j=it.first-1;j>=0;j--)
            if(school[j][it.second]=='S') return true;
            else if(school[j][it.second]=='O') break;
        for(int j=it.first;j<school.size();j++)
            if(school[j][it.second]=='S') return true;
            else if(school[j][it.second]=='O') break;
    }
    return false;
}
void DFS(int count, int n, vector<vector<char>> &school){
    if(count==3){
        if(!teacher_monitor(school) || flag)
            flag = true;
        return;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(school[i][j]=='X'){
                school[i][j]='O';
                DFS(count+1,n,school);
                school[i][j]='X';
            }
        }
    }
}


int main(){
  int n;
  cin >> n;
  vector<vector<char>> school(n,vector<char>(n));
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        cin >> school[i][j];
        if(school[i][j] == 'T') teacher.push_back({i,j});
    }
  DFS(0,n,school);
  if(flag)
    cout << "YES";
  else
    cout << "NO";
}