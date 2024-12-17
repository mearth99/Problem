#include <bits/stdc++.h>
using namespace std;

int N,M;
bool node[1001];
vector<int> arr[1001];
void DFS(int cur){
	node[cur] = 1;
	for(auto it: arr[cur])
		if(!node[it])
			DFS(it);
} 

void solution(){
	int count = 0;
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int from, to;
		cin >> from >> to;
		arr[from].push_back(to);
		arr[to].push_back(from);
	}

	for(int i=1;i<=N;i++){
		if(!node[i]){
			DFS(i);
			count++;
		}
	}
	cout << count;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}