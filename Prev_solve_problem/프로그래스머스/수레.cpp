#include <string>
#include <vector>
#include <queue>
using namespace std;

int Rvisit[4][4]={0};
int Bvisit[4][4]={0};
int n,m,mincount=9999;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

vector<vector<int>> map;
struct pos{
	int x,y;
};
pos r_start, r_end, b_start, b_end;
struct cart{
	pos R;
	pos B;
	int count;
	bool B_flag;
	bool R_flag;
};


int BFS(){
	queue<cart> q;
	q.push({r_start,r_end,0,false,false});
	while(!q.empty()){
		cart cur = q.front(); q.pop();
		if(cur.B.x==b_end.x && cur.B.y==b_end.y) cur.B_flag = true;
		if(cur.R.x==r_end.x && cur.R.y==r_end.y) cur.R_flag = true;
		if(cur.R_flag && cur.B_flag) min(cur.count, mincount);
		for(int i=0;i<4;i++){
			int nbx = cur.B.x + dx[i];
			int nby = cur.B.y + dy[i];
			if(cur.B_flag){
				nbx = cur.B.x;
				nby = cur.B.y;
			}
			for(int j=0;j<4;j++){
				int nrx = cur.R.x + dx[i];
				int nry = cur.R.y + dy[i];
				if(cur.R_flag){
					nrx = cur.R.x;
					nry = cur.R.y;
				}
				if(nbx < 0 || nrx < 0 || nbx >= m || nrx >=m || nby <0 || nby >= n || nry < 0 || nry >= n || map[nby][nbx]==5 || map[nry][nrx]==5) continue;
				if(!cur.B_flag && Bvisit[nby][nbx] || !cur.R_flag && Rvisit[nry][nrx]) continue;
				if(nbx == nrx && nby == nry) continue;

				Bvisit[nby][nbx] = true;
				Rvisit[nry][nrx] = true;
			}
		}

	}
}

int solution(vector<vector<int>> maze) {
    int answer = 0;
	n = maze.size();
	m = maze[0].size();
	map = maze;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(maze[i][j]==1){
				r_start.x = j;
				r_start.y = i;
			}
			else if(maze[i][j]==2){
				r_end.x = j;
				r_end.y = i;
			}
			else if(maze[i][j]==3){
				b_start.x = j;
				b_start.y = i;
			}
			else if(maze[i][j]==4){
				b_end.x = j;
				b_end.y = i;
			}
		}
	}
	BFS();
    return answer;
}