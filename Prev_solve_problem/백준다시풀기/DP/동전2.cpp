#include <bits/stdc++.h>
using namespace std;
//BFS를 통한 문제 해결.
int ARR[101];
int N,K;
int cnt = 1000000;

void BFS(){
	queue<pair<int,int>> q;
	q.push({0,0});
	while(!q.empty()){
		pair<int,int> target = q.front();
		q.pop();
		if(target.first > K) continue;
		if(target.first == K){
			cnt = min(cnt,target.second);
			continue;
		}
		for(int i=0;i<N;i++)
			q.push({target.first + ARR[i],target.second+1});
	}
}
void DFS(int money, int count){
	if(money > K) return;
	if(money == K){
		cnt = min(cnt, count);
		return;
	}
	for(int i=0;i<N;i++)
		DFS(money+ARR[i],count+1);
}

void solution(){
	cin >> N >> K;
	for(int i=0;i<N;i++){
		cin >> ARR[i];
	}
	BFS();
	cout << cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}