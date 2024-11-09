#include<vector>
#include<algorithm>
#include<queue>
#include<iostream>

using namespace std;

vector<int> tree[100001];
int DP[100001];

void search_tree(int node, int parent){
    for(auto it : tree[node])
        if(it!=parent)
            search_tree(it,node);
        
    DP[node] = 1;
    for(auto it : tree[node])
        DP[node] += DP[it];  
    return;
}
int main(){
    //트리와 쿼리에서는 최상위 부모가 존재하기 때문에, 부모 관계가 존재함으로써 모든 그래프에 대해 부모를 설정한 후 탐색할 필요가 없다.
    //다만, 트리의 계수가 아주 많고, 서브트리를 계산하기 때문에, DP 방식으로 설계한다면 비용을 많이 줄일 수 있다.
    /*
        재귀적인 방식으로 그래프를 탐색하면서 DP를 채워나가자.
    */
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, r, q;    
    cin >> n >> r >> q;
    for(int i=0;i<n-1;i++){
        int f,t;
        cin >> f >> t;
        tree[f].push_back(t);
        tree[t].push_back(f);
    }
    search_tree(r,0);
    for(int i=0;i<q;i++){
        int out;
        cin >> out;
        cout << DP[out] << '\n';
    }
    return 0;
}