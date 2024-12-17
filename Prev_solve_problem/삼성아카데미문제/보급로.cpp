#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
#define INF 987654321

vector<int> outputs;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int N;
vector<vector<int>> arr;
vector<vector<int>> node;
struct constr{
	int x,y,cost;
};

struct cmp{
	bool operator()(constr &p1, constr &p2){
		return p1.cost > p2.cost;
	}
};

int main(int argc, char** argv)
{
	freopen("/mnt/c/Users/dlwls/Downloads/input.txt", "r", stdin);
	freopen("/mnt/c/Users/dlwls/Downloads/myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		//다익스트라큐를 이용하여 우선순위 큐 -> 가장 적은 비용 구하기
		cin >> N;
		arr.clear();
		node.clear();
		arr.resize(N,vector<int>(N,0));
		node.resize(N,vector<int>(N,INF));
		
		for(int i=0;i<N;i++){
			string temp;
			cin >> temp;
			for(int j=0;j<temp.length();j++){
				arr[i][j] = temp.at(j) - '0';
			}
		}
		priority_queue<constr, vector<constr>, cmp> q;
		q.push({0,0,0});
		node[0][0] = 0;
		while(!q.empty()){
			constr target = q.top(); q.pop();
			if(target.x==N-1 && target.y==N-1) {
				outputs.push_back(target.cost);
				break;
			}
			if(target.cost > node[target.y][target.x]) continue;
			for(int i=0;i<4;i++){
				int nx = target.x + dx[i];
				int ny = target.y + dy[i];
				if(nx>=0&&nx<N&&ny>=0&&ny<N){
					int nextcost = target.cost + arr[ny][nx];
					if(node[ny][nx] > nextcost){
						node[ny][nx] = nextcost;
						q.push({nx,ny,nextcost});
					}
				}
			}
		}
	}
	int a = 1;
	for(auto it : outputs)
		cout << '#' << a++ << ' ' << it << '\n';
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}