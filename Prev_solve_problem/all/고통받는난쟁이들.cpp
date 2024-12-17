
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 200005

int arr[MAX];
int mintree[MAX*4];
int maxtree[MAX*4];

int minupdate(int start, int end, int node, int index, int value){
	if(index < start || index > end) return mintree[node];
	if(start == end) return mintree[node] = value;
	int mid = (start + end) / 2;
	return mintree[node] = min(minupdate(start,mid,node*2,index, value), minupdate(mid+1,end,node*2+1,index, value));
}
int maxupdate(int start, int end, int node, int index, int value){
	if(index < start || index > end) return maxtree[node];
	if(start == end) return maxtree[node] = value;
	int mid = (start + end) / 2;
	return maxtree[node] = max(maxupdate(start,mid,node*2,index, value), maxupdate(mid+1,end,node*2+1,index, value));
}
int GetMin(int start, int end, int node, int left, int right){
	if(left>end || right<start) return INT32_MAX;
	if(left<=start && right >=end) return mintree[node];
	int mid = (start + end) / 2;
	return min(GetMin(start,mid,node*2,left,right),GetMin(mid+1,end,node*2+1,left,right));
}
int GetMax(int start, int end, int node, int left, int right){
	if(left>end || right<start) return -1;
	if(left<=start && right >=end) return maxtree[node];
	int mid = (start + end) / 2;
	return max(GetMax(start,mid,node*2,left,right),GetMax(mid+1,end,node*2+1,left,right));
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int N,M;
	cin >> N >> M;
	for(int i=1;i<=N;i++){
		cin >> arr[i];
		minupdate(1,N,1,arr[i],i);
		maxupdate(1,N,1,arr[i],i);
	}
	for(int i=0;i<M;i++){
		int select, from, to;
		cin >> select >> from >> to;
		if(select==1){
			minupdate(1,N,1,arr[to],from);
			minupdate(1,N,1,arr[from],to);
			maxupdate(1,N,1,arr[to],from);
			maxupdate(1,N,1,arr[from],to);
			swap(arr[to],arr[from]);
		}else{
			int seq = GetMax(1,N,1,from,to) - GetMin(1,N,1,from,to);
			if(to-from == seq) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}