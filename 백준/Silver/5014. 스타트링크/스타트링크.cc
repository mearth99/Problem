#include <bits/stdc++.h>
using namespace std;
int F,S,G,U,D;

vector<int> arr;

void solution(){
	cin >> F >> S >> G >> U >> D;
	arr.resize(F+5,0);
	queue<int> q;
	q.push(S);
	arr[S] = 1;
	while(!q.empty()){
		int t = q.front(); q.pop();
		if(t+U<=F && !arr[t+U]){
			arr[t+U] = arr[t]+1;
			q.push(t+U);
		}
		if(t-D>0 && !arr[t-D]){
			arr[t-D] = arr[t]+1;
			q.push(t-D);
		}
	}
	if(arr[G]==0) cout << "use the stairs";
	else cout << arr[G]-1;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}
