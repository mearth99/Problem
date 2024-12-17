#include <bits/stdc++.h>
using namespace std;

int arr[101][101];
vector<int> parent(101);

int N, from, to, K, output=9999, flag=false;
void DFS(int count, int now){
	if(flag) return;
	if(now == to){
		output = min(output,count);
		flag = true;
		return;
	}
	for(int i=0;i<101;i++){
		if(arr[now][i]==1){
			arr[now][i] = 0;
			DFS(count+1,i);
		}
	}
	if(!flag) DFS(count+1, parent[now]);

}

void solution(){
	cin >> N >> from >> to >> K;
	
	for(int i=0;i<K;i++){
		int a,b;
		cin >> a >> b;
		arr[a][b] = 1;
		parent[b] = a;
	}
	DFS(1,from);
	cout << output;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}

