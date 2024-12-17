#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
long long alpabet[26];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
struct rocket{
	long long cost;
	int y, x;		
};
struct cmp{
	bool operator()(rocket p1, rocket p2){
		return p1.cost > p2.cost;
	}
};

long long node[1001][1001];
char arr[1001][1001];
void Sol(){
	
	for(int i=0;i<1001;i++){
		for(int j=0;j<1001;j++)
			node[i][j] = (long long)1e18;
	}
	int K, W, H;
	cin >> K >> W >> H;
	
	priority_queue<rocket, vector<rocket>,cmp> pq;
	for(int i=0;i<K;i++){
		char al;
		cin >> al;
		long long value;
		cin >> value;
		alpabet[al-'A'] = value;
	}
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cin >> arr[i][j];
			if(arr[i][j] == 'E') pq.push({0,i,j});
		}
	}
	while(!pq.empty()){
		rocket cur = pq.top();
		pq.pop();
		if(node[cur.y][cur.x]<cur.cost) continue;
		if(cur.y==0 || cur.y == H-1 || cur.x ==0 || cur.y ==0){
			cout << cur.cost << endl;
			return;
		}
		for(int i=0;i<4;i++){
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if(ny<H && ny >=0 && nx<W && nx>=0){
				long long nextcost = cur.cost + alpabet[arr[ny][nx]-'A'];
				if(node[ny][nx]< nextcost) continue;
				node[ny][nx] = nextcost;
				pq.push({nextcost, ny,nx});
			}
		}
	}
}

int main(){
	int T;
	cin >> T;
	while(T-->0){
		Sol();
	}
	return 0;
}