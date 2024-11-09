#include<bits/stdc++.h>
using namespace std;
int board[102][102];
int visited[102];
int n, m, a, b, x, y;
queue<int> q;
void bfs(int k){
	q.push(k);
	visited[k] = 1;
	while(!q.empty()){
		auto cur = q.front();
		q.pop();
		for(int i = 1; i <= n; i++){
			if(board[cur][i] == 1 && visited[i] == 0){
				q.push(i);
				visited[i] = visited[cur] + 1; // 해당 조건을 만족할 때마다 촌수가 1씩 늘어난다.
			}
		}
	}
}
int main(){
	cin >> n;
	cin >> a >> b;
	cin >> m;
	while(m--){
		cin >> x >> y;
		board[x][y] = 1;  // 가족간의 연결관계 표시
		board[y][x] = 1;
	}
	bfs(a); // 입력값 a에 대하여 촌수계산(bfs 시행)
	if(visited[b] == 0){ // 촌수가 없는 관계라면 -1 출력
		cout << "-1\n";
	}
	else{
		cout << visited[b] - 1<< '\n'; // 촌수가 있는 관계라면 (촌수-1) 출력. 왜냐하면, 처음 q에 a값을 넣었을 때, visited[a] = 1로 했기 때문에(본인을 1촌으로 계산한 것이다.) 
	}
	return 0;
}