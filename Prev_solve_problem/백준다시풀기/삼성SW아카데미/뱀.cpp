#include <bits/stdc++.h>
using namespace std;

struct snake{
	pair<int,int> head;
	pair<int,int> tail;
	int dir; // 0,1,2,3 -> 상, 우, 하, 좌
	int live_time;
	int length;
};
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void print(int N, int arr[101][101]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void solution(){
	int N, K, L;
	snake nake = {{0,0},{0,0},1,0,1};
	cin >> N >> K;
	
	queue<pair<int,int>> q; //-1이 L , 1이 R
	// vector<vector<int>> arr(N, vector<int>(N)); //-1은 사과 1이상 값은 뱀
	int arr[101][101] = {0};
	for(int i=0;i<K;i++){
		int y,x;
		cin >> y >> x;
		arr[y-1][x-1] = -1;
	}
	cin >> L;
	for(int i=0;i<L;i++){
		int x;
		char c;
		cin >> x >> c;
		if(c=='L')
			q.push({x,-1});
		else
			q.push({x,1});
	}
	arr[0][0] = 1;
	while(1){
		// print(N,arr);
		nake.head.first += dy[nake.dir];
		nake.head.second += dx[nake.dir];
		nake.live_time++;
		if(nake.live_time == q.front().first){
			nake.dir += q.front().second;
			if(nake.dir<0) nake.dir = 3;
			if(nake.dir>3) nake.dir = 0;
			q.pop();
		}
		if(nake.head.first<0 || nake.head.first>=N || nake.head.second<0 || nake.head.second>=N){
			//뱀이 외각으로 나가버리면 종료한다.
			break;
		}
		if(arr[nake.head.first][nake.head.second]>0) //머리가 몸통에 박치기하면 종료한다.
			break;

		if(arr[nake.head.first][nake.head.second]==-1){ //뱀이 사과에 접근한다면 뱀은 길어지고 꼬리는 제자리에 있는다.
			nake.length++;
			arr[nake.head.first][nake.head.second] = 0; //사과먹었으니 값 치운다.
		}else{
			//뱀이 사과를 먹지 못했다면, 뱀의 꼬리가 줄어든다. 뱀의 length가 가장 작은 부분이 tail이 된다.
			int maxv = 9999;
			int dir = -1;
			for(int i=0;i<4;i++){
				if(nake.tail.first + dy[i]>=0 && nake.tail.first + dy[i] < N && nake.tail.second + dx[i]>=0 && nake.tail.second + dx[i]<N){
					if(arr[nake.tail.first + dy[i]][nake.tail.second+ dx[i]] < maxv && arr[nake.tail.first + dy[i]][nake.tail.second+ dx[i]]!=0){
						maxv = arr[nake.tail.first][nake.tail.second];
						dir = i;
					}
				}
			}
			if(nake.length!=1 && dir!=-1){
				arr[nake.tail.first][nake.tail.second] = 0; //꼬리가 움직이면서 값을 없앤다.
				nake.tail.first += dy[dir];
				nake.tail.second += dx[dir];
			}else{
				arr[nake.tail.first][nake.tail.second] = 0;
				nake.tail.first = nake.head.first;
				nake.tail.second = nake.head.second;
			}

		}
		arr[nake.head.first][nake.head.second] = nake.length; //종료조건이 아니면 머리가 도착한 것이다.
		
		
	}
	cout << nake.live_time;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}