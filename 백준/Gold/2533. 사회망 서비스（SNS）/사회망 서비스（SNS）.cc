#include<vector>
#include<algorithm>
#include<queue>
#include<iostream>
#include<cstring>
using namespace std;

vector<int> tree[1000001];
bool visit[1000001];
int DP[1000001][2];
void search_tree(int node){
    visit[node] = true;
    DP[node][0] = 1; //얼리어답터
    DP[node][1] = 0; //일반인
    for(auto it : tree[node])
        if(!visit[it]){  
            search_tree(it);
            DP[node][0] += min(DP[it][0],DP[it][1]);
            DP[node][1] += DP[it][0];
        }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, from, to;   
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }
    search_tree(1);
    cout << min(DP[1][0],DP[1][1]) << '\n';
    return 0;
}