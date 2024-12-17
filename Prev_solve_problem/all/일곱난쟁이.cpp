
#include <bits/stdc++.h>
using namespace std;
vector<int> arr(9);
int visited[9] = {0};
int selects = 0;
int flag = 0;
void DFS(int sum){
	if(flag == 1) return;
	if(selects==7 && sum==100){
		for(int i=0;i<9;i++){
			if(visited[i])
				cout << arr[i] << '\n';
		}
		flag = 1;
		return;
	}
	for(int i=0;i<9;i++){
		if(!visited[i]){
			visited[i] = 1;
			selects++;
			DFS(sum + arr[i]);
			selects--;
			visited[i] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	for(int i=0;i<9;i++){
		cin >> arr[i];
	}
	sort(arr.begin(),arr.end());
	DFS(0);
	return 0;
}