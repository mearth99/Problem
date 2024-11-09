#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct room{
	int cost, from, to;
};


int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int arr[101][101];
int visited[101][101];
int main(){
	for(int i=0;i<101;i++)
		for(int j=0;j<101;j++)
			visited[i][j] = 999;
	int N, M;
	cin >> N >> M;
	for(int i=1;i<=M;i++){
		string temp;
		cin >> temp;
		for(int j=1;j<=temp.size();j++){
			arr[i][j] = temp.at(j-1) - '0';
		}
	}
	deque<room> pq;
	pq.push_front({0,1,1});
	while(!pq.empty()){
		int cost = pq.front().cost;
		int y = pq.front().from;
		int x = pq.front().to;
		pq.pop_front();
		if(x==N && y == M){
			cout << cost;
			break;
		}
		for(int i=0;i<4;i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny>=1 && ny<=M && nx>=1 && nx<=N && visited[ny][nx] > cost){
				if(arr[ny][nx]==0){
					visited[ny][nx] = cost;
					pq.push_front({cost,ny,nx});
				}else{
					visited[ny][nx] = cost;
					pq.push_back({cost+1,ny,nx});
				}
			}
		}
	}

	return 0;
}