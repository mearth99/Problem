#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <deque>
using namespace std;

vector<int> arr[1001];
int visited[1001];
int main(){
	int a,b,N,M,output = -1;
	bool flag = false;
	cin >> a >> b;
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int from, to;
		cin >> from >> to;
		arr[from].push_back(to);
		arr[to].push_back(from);
	}
	queue<pair<int,int>> q;
	q.push({a,0});
	visited[a] = 1;
	while(!q.empty()){
		pair cur = q.front();
		q.pop();
		if(cur.first == b){
			output = cur.second;
			break;
		}
		for(auto it: arr[cur.first]){
			if(visited[it]) continue;
			q.push({it,cur.second+1});
			visited[it] = 1;
		}
	}
	cout << output;
	return 0;
}