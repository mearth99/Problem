#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

bool visited[501][501];
vector<pair<int, set<int>>> width;

int startvalue = 1;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int n,m;
pair<int, set<int>> BFS(int y, int x, vector<vector<int>> land){
	set<int> having;
	queue<pair<int,int>> q;
	q.push({y,x});
	visited[y][x] = true;
	having.insert(x);
	int groupsize = 1;
	while(!q.empty()){
		int cur_y  = q.front().first;
		int cur_x  = q.front().second; q.pop();	
		for(int i=0;i<4;i++){
			int nx = dx[i] + cur_x;
			int ny = dy[i] + cur_y;
			if(nx<0 || nx>=m || ny<0 || ny>=n || land[ny][nx]==0 || visited[ny][nx]) 
				continue;
			q.push({ny,nx});
			visited[ny][nx] = true;
			groupsize++;
			having.insert(nx);
		}
	}
	return {groupsize, having};
}

int solution(vector<vector<int>> land) {
    n = land.size();
	m = land[0].size();

	int answer[501] = {0};
	int value = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(land[i][j]==0 || visited[i][j]) continue;
			width.push_back(BFS(i,j,land));
		}
	}
	for(auto i : width){
		for(auto it : i.second){
			answer[it] += i.first;
			value = max(value, answer[it]);
		}
	}
	
    return value;
}

int main(){
	vector<vector<int>> a = {{0, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 1, 0, 0}, {1, 1, 0, 0, 0, 1, 1, 0}, {1, 1, 1, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 1, 1}};
	solution(a);
	return 0;
}