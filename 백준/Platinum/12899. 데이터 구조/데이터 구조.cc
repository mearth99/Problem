#include <bits/stdc++.h>
using namespace std;
#define MAX 2000001

int arr[MAX];
int tree[MAX*4];
void Update_tree(int start, int end, int node, int index, int value){
    if(start > index || end < index) return;
    tree[node] += value;
    if(start == end) return;
    int mid = (start + end) >> 1;
    Update_tree(start, mid, node*2, index, value);
    Update_tree(mid+1, end, node*2+1, index, value);
    return;
}
int query(int start, int end, int node, int value){
    tree[node]--;
    if(start == end) return start;
    int mid = (start + end) >> 1;
    if(value <= tree[node*2]) return query(start, mid,node*2, value);
    else return query(mid+1, end,node*2+1,value - tree[node*2]);
}

void solve(){
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int T, X;
        cin >> T >> X;
        if(T==1){
            Update_tree(1,MAX,1,X,1);
        }else{
            cout << query(1,MAX,1,X) << '\n';
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    solve();
    return 0;
}