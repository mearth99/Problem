#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

vector<int> outputs;
vector<vector<int>> maze;
vector<vector<bool>> visited;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int flag = 0; 
void DFS(int cy, int cx, int ey, int ex){
	visited[cy][cx] = true;
	if(maze[cy][cx]==3){
		flag = 1;
		return;
	}
	for(int i=0;i<4;i++){
		int nx = cx + dx[i];
		int ny = cy + dy[i];
		if(nx>=0 && nx<100 && ny>=0 && ny<100 && maze[ny][nx]!=1 && !visited[ny][nx]){
			DFS(ny,nx,ey,ex);
		}
	}
}
int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	

	for(test_case = 1; test_case <= 10; ++test_case){
		int sy,sx,ey,ex;
		flag=0;
		cin>>T;
		maze.clear();
		visited.clear();
		maze.resize(100,vector<int>(100,0));
		visited.resize(100,vector<bool>(100,false));
		for(int i=0;i<100;i++){
			string temp;
			cin >> temp;
			for(int j=0;j<temp.length();j++){
				maze[i][j] = temp.at(j) - '0';
				if(maze[i][j]==2){
					sy = i;
					sx = j;
				}
				if(maze[i][j]==3){
					ey = i;
					ex = j;
				}
			}
		}
		DFS(sy,sx,ey,ex);
		outputs.push_back(flag);
	
	}
	int a = 1;
	for(auto it : outputs)
		cout << '#' << a++ << ' ' << it << '\n';
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}