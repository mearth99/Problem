#include <bits/stdc++.h>
using namespace std;

vector<long long> num;
vector<long long> sum;

int segment_recursive(int node, int start, int end){
    if(start==end) return sum[node] = num[start];
    int mid = (start + end) /2;
    int left = segment_recursive(node*2,start,mid);
    int right = segment_recursive(node*2+1,mid+1,end);
    return sum[node] = left+right;
}
int get_segment_recursive(int node, int start, int end, int left, int right){
    if(left > end || right < start ) return 0;
    if(left <= start && end <= right ) return sum[node];
    int mid = (start + end) / 2;
    int leftv = get_segment_recursive(node*2, start, mid, left ,right);
    int rightv = get_segment_recursive(node*2+1, mid+1, end, left ,right);
    return leftv + rightv;
}
void update_segment_recursive(int node, int start, int end, int index, int diff){
    if(index < start || index > end) return;
    sum[node] = sum[node] + diff;

    if(start != end){
        int mid = (start + end) / 2;
        update_segment_recursive(node*2, start, mid, index ,diff);
        update_segment_recursive(node*2+1, mid+1, end, index ,diff);
    }
}

int main(){
    int N,Q;
    long long temp;
    cin >> N >> Q;
    for(int i=0;i<N;i++){
        cin >> temp;
        num.push_back(temp);
    }
    int height = (int)ceil(log2(N));
    int tree_size = (1 << (height+1));
    sum.resize(tree_size);
    segment_recursive(1,0,N-1);
    for(int i=0;i<Q;i++){
        int x,y,a,b;
        cin >> x >> y >> a >> b;
        x--; y--; a--;
        cout << get_segment_recursive(1,0,N-1,x,y) << endl;
        update_segment_recursive(1,0,N-1,a,b);
    }
    return 0;
}