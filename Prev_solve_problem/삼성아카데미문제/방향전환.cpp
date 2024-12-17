#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

struct moves{
	int x, y, cnt, dir;
};

vector<int> outputs;
bool visited[201][201][2];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int BFS(int x1, int y1, int x2, int y2){
	int output = 987654312;
	queue<moves> q;
	q.push({x1,y1,0,false}); //세로이동하세요
	q.push({x1,y1,0,true}); //가로이동하세요
	visited[y1][x1][0] = true;
	visited[y1][x1][1] = true;
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		int dir = q.front().dir;
		q.pop();
		if(x==x2 && y==y2){
			output = min(cnt,output);
			continue;
		}
		for(int i=0;i<2;i++){
			int nx,ny;
			if(dir){
				nx = x + dx[i];
				ny = y + dy[i];
			}else{
				nx = x + dx[i+2];
				ny = y + dy[i+2];	
			}
			if(nx>=0 && nx <= 200 && ny>=0 && ny<=200 && !visited[ny][nx][dir]){
				visited[ny][nx][dir] = true;
				if(dir)
					q.push({nx,ny,cnt+1,false});
				else
					q.push({nx,ny,cnt+1,true});
			}
		}
	}
	return output;
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		memset(visited,0,sizeof(visited));
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		outputs.push_back(BFS(x1+100,y1+100,x2+100,y2+100));

	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}