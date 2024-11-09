#include <bits/stdc++.h>
#define MAX 1000001


using namespace std;
using ll = long long;

ll arr[MAX];
ll tree[MAX*4];

void init(int start, int end, int node){
    if(start == end){
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) >> 1;
    init(start, mid, node*2);
    init(mid+1, end, node*2+1);
    return;
}

void update_section_sum(int start, int end, int node, int left, int right, int k){
    if(left <= start && end <= right) {
        tree[node] += k;
        return;
    }
    if(left > end || right < start) return;
    int mid = (start + end) >> 1;
    update_section_sum(start, mid, node*2, left, right, k);
    update_section_sum(mid+1, end, node*2+1, left, right, k);
}
ll get_section(int start, int end, int node, int idx, ll prev){
    if(idx < start || idx > end) return 0;
    prev += tree[node];
    if(start == end) return prev;
    int mid = (start + end) >> 1;
    return get_section(start, mid, node*2, idx, prev) + get_section(mid+1, end, node*2+1, idx, prev);

}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    int N, M;
    
    cin >> N;
    for(int i=0;i<N;i++)
        cin >> arr[i];
    init(0,N-1,1);
    cin >> M;
    for(int i=0;i<M;i++){
        int q, qi, qj, qk;
        cin >> q;
        if(q==1){
            cin >> qi >> qj >> qk;
            update_section_sum(0, N-1, 1, qi-1, qj-1, qk);
        }else{
            cin >> qi;
            cout << get_section(0,N-1,1,qi-1,0) << '\n';
        }
    }
    return 0;
}
