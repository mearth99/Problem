#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
long long arr[MAX];
long long tree[MAX*4];
int N, M, K;
long long make_segment(int start, int end, int node){
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = (make_segment(start, mid, node * 2) * make_segment(mid+1, end, node*2+1))%1000000007; 
}
long long get_sum_segment(int start, int end, int node, int left, int right){
    if(left > end || right < start) return 1;
    if(left <= start && end<=right) return tree[node];
    int mid = (start + end) / 2;
    return (get_sum_segment(start, mid, node*2, left, right) * get_sum_segment(mid+1, end, node*2+1, left, right))%1000000007;
}
void update_segment(int start, int end, int node, int index, long long diff){
    if(index < start || index > end) return;
    if(start == end){
        tree[node] = diff;
        return;
    }
    int mid = (start + end) / 2;
    update_segment(start, mid, node*2, index, diff);
    update_segment(mid+1, end, node*2+1, index, diff);
    tree[node] = (tree[node*2] * tree[node*2+1]) % 1000000007;
}

int main(){
    
    cin >> N >> M >> K;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    make_segment(0,N-1,1);
    long long a,b,c;
    for(int i=0;i<M+K;i++){
        cin >> a >> b >> c;
        if(a==1) {
            update_segment(0, N-1, 1, b-1, c);
        }
        if(a==2) cout << get_sum_segment(0,N-1,1,b-1,c-1) << '\n';
    }
    return 0;
}