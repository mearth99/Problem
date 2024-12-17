#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <set>
#include <string>
using namespace std;

vector<int> outputs;
set<string> s;
int arr[4][4];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

struct block{
	int y, x, cnt;
	string text;
};

void BFS(int y, int x){
	queue<block> q;
	q.push({y,x,0,""});
	while(!q.empty()){
		block cur = q.front(); q.pop();
		cur.text += (arr[cur.y][cur.x] + '0');
		cur.cnt++;
		if(cur.cnt==7){
			s.insert(cur.text);
			continue;
		}else{
			for(int i=0;i<4;i++){
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if(nx>=0 && nx<4 && ny>=0 && ny<4)
					q.push({ny,nx,cur.cnt,cur.text});
			}
		}
	}

}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
		
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				cin >> arr[i][j];
			}
		}
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				BFS(i,j);
			}
		}
		outputs.push_back(s.size());
		s.clear();
	}
	int a = 1;
	for(auto it : outputs)
		cout << '#' << a++ << ' ' << it << '\n';
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}