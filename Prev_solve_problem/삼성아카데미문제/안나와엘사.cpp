#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

/*
* 문제 설명 및 링크
*/
/*
* 소감
이문제는 단순히 안나와 엘사가 만나는게 아닌, 안나의 위치에 따라 엘사가 영향받기 때문에
하나하나 BFS안에 BFS를 넣어서 돌려야하는 점이 까다로웠다.

그래도 코드를 짧게 만들수있었다.
*/
struct moves{
	int y, x, day;
};
int dy[8] = { -1,0,1,0,1,1,-1,-1 };
int dx[8] = { 0,-1,0,1,1,-1,1,-1 };
vector<vector<int>> arr;

int check(int y1, int x1, int y2, int x2){
	if((y1+2>=y2) && y1-2<=y2 && x1+2>=x2 && x1-1<=x2) return 4;
	else return 0;
}

bool BFS_elsa(int ey, int ex, int sy, int sx, int limit){
	int visit[5][5] = {0};
	queue<moves> q;
	q.push({sy,sx,0});
	visit[sy][sx] = 1;
	while(!q.empty()){
		int y = q.front().y;
		int x = q.front().x;
		int day = q.front().day;
		q.pop();
		if(day > limit) continue;
		if(y == ey && x == ex) return true;
		int gap = check(ey,ex,y,x);
		for(int i=0;i<8-gap;i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny>=0 && ny < N && nx>=0 && nx < N && !visit[ny][nx] && arr[ny][nx]==1){
				visit[ny][nx] = 1;
				q.push({ny,nx});
			}
		}
	}
	return false;
}
int BFS_anna(int sy, int sx, int ey, int ex){
	int visit[5][5] = {0};
	queue<moves> q;
	q.push({sy,sx,0});
	visit[sy][sx] = 1;
	while(!q.empty()){
		int y = q.front().y;
		int x = q.front().x;
		int day = q.front().day;
		q.pop();
		if((BFS_elsa(y,x,ey,ex, day))) return day;
		
		for(int i=0;i<4;i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny>=0 && ny < N && nx>=0 && nx < N && !visit[ny][nx] && arr[ny][nx]==1){
				visit[ny][nx] = 1;
				q.push({ny,nx});
			}
		}

	}
	return -1;
}


int N,M;
void solution() {
	cin >> N;
	arr.resize(N,vector<int>(N));
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			char temp;
			cin >> temp;
			if(temp == '#') arr[i][j] = -1;
			else arr[i][j] = 1;
		}
	}
	int ey,ex,ay,ax;
	cin >> ey >> ex >> ay >> ax;

	cout << BFS_anna(ay,ax, ey, ex) << " sec";

}

int main() {

	cin.tie(NULL); ios_base::sync_with_stdio(false);
	solution();

	return 0;
}

