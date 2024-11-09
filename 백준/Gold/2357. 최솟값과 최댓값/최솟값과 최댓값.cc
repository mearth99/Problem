#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
int arr[MAX];
int tree[MAX*4]; //max
int tree2[MAX*4]; //min

pair<int,int> make_segment(int start, int end, int node){
    if(start == end){
        tree[node] = arr[start];
        tree2[node] = arr[start];
        return {tree[node],tree2[node]};
    } 
    int mid = (start + end) / 2;
    pair<int,int> left_segment, right_segment;
    left_segment = make_segment(start, mid, node*2);
    right_segment = make_segment(mid+1, end, node*2+1);
    tree[node] = max(left_segment.first, right_segment.first);
    tree2[node] = min(left_segment.second, right_segment.second);
    return {tree[node],tree2[node]};
}

pair<int,int> get_segment(int start, int end, int node, int left, int right){
    if(left > end || right < start) return {INT32_MAX,0};
    if(left <= start && end<=right) return {tree2[node],tree[node]};
    int mid = (start + end) / 2;
    pair<int,int> left_segment,right_segment;
    left_segment = get_segment(start, mid, node*2, left, right);
    right_segment = get_segment(mid+1, end, node*2+1, left, right);
    return {min(left_segment.first, right_segment.first), max(left_segment.second, right_segment.second)};
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    make_segment(0,N-1,1);
    int a,b;
    for(int i=0;i<M;i++){
        cin >> a >> b;
        pair<int,int> result = get_segment(0,N-1,1,a-1,b-1);
        printf("%d %d\n",result.first, result.second);
    }
    return 0;
}