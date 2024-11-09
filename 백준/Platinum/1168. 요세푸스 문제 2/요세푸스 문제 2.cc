#include <bits/stdc++.h>
using namespace std;
#define MAX 2000001

int arr[MAX];
int tree[MAX*4];
int init(int start, int end, int node){
    if(start == end) return tree[node] = 1;
    int mid = (start + end) >> 1;
    return tree[node] = init(start, mid, node*2) + init(mid+1,end,node*2+1);
}
int Print(int start, int end, int node, int index){
    tree[node]--;
    if(start == end) return start;
    int mid = (start + end) >> 1;
    if(index > tree[node*2]) return Print(mid+1, end, node*2+1, index-tree[node*2]);
    else return Print(start, mid, node*2, index);
}

void solve(){
    int N, K;
    cin >> N >> K;
    int ordered = K-1;
    init(1,N,1);
    cout << '<';
    for(int i=1;i<=N;i++){
        if(i!=N)
            cout << Print(1,N,1, ordered+1) << ", ";
        else
            cout << Print(1,N,1, ordered+1);
        if(tree[1]==0) break;
        ordered = (ordered + K-1) % tree[1];
    }
    cout << '>';
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    solve();
    return 0;
}