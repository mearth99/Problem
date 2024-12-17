#include <bits/stdc++.h>
#define MAX 100001


using namespace std;

int arr[MAX];
pair<int,int> tree[MAX*4]; //first : min, second : max
//선반에 중복이 없다면, LR사이 순서 상관없이 LR 범위에 해당하는지 안하는지 확인하면 된다.
//start == end일때 left <=  target <= right 이면 OK
//else라면 No 
pair<int,int> init(int start, int end, int node){
    if(start==end)
        return tree[node] = make_pair(start, start);

    int mid = (start + end) /2;
    pair<int,int> left_tree = init(start, mid, node *2);
    pair<int,int> right_tree = init(mid+1, end, node *2 +1);
    return tree[node] = {min(left_tree.first, right_tree.first), max(left_tree.second, right_tree.second)};
    
}
pair<int,int> get_section(int start, int end, int node, int left, int right){
    if(start > right || end < left) return make_pair(INT_MAX, -INT_MAX);
    if(left<=start && end <=right) return tree[node];
    int mid = (start + end) / 2;
    pair<int,int> left_tree = get_section(start, mid, node*2, left, right);
    pair<int,int> right_tree = get_section(mid+1, end, node*2+1, left, right);
    return {min(left_tree.first, right_tree.first), max(left_tree.second, right_tree.second)};
}


pair<int,int> update_section(int start, int end, int node, int index, int diff){
    if(index < start || index > end) return tree[node]; // index가 구간에 없는 경우 더 이상 계산할 필요가 없기 때문에 끝낸다.
    if(start == end) return tree[node] = make_pair(diff,diff);
	int mid = (start + end) / 2;
	pair<int,int> left_tree = update_section(start, mid, node*2, index, diff); //재귀를 통해 왼쪽, 오른쪽을 가면서 목적지 트리를 찾아나간다.
	pair<int,int> right_tree = update_section(mid+1, end, node*2+1, index, diff);
    return tree[node] = {min(left_tree.first, right_tree.first), max(left_tree.second, right_tree.second)};
}


int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n,k;
        cin >> n >> k;
        init(0,n-1,1);
        for(int i=0;i<n;i++){
            arr[i] = i;
        }
        for(int i=0;i<k;i++){
            int Q, A, B;
            cin >> Q >> A >> B;
            if(Q==0){
                update_section(0,n-1,1,arr[A],B);
                update_section(0,n-1,1,arr[B],A);
                swap(arr[A],arr[B]);
            }else{
                pair<int,int> value = get_section(0,n-1,1,A,B);
                if(value.first == A && value.second == B) cout << "YES\n";
                else cout << "No\n";
            }
        }
        
    }
    return 0;
}
