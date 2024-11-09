#include<vector>
#include<algorithm>
#include<queue>
#include<iostream>
#include<cstring>
using namespace std;

vector<int> tree[10001];
int weight[10001];
bool visit[10001];
int DP[10001][2];
void search_tree(int node){
    visit[node] = true;
    DP[node][1] = weight[node];
    //DP[0] -> 일반마을
    //DP[1] -> 우수마을
    for(auto it : tree[node])
        if(!visit[it]){  
            search_tree(it);
            DP[node][0] += max(DP[it][0],DP[it][1]);
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
    for(int i=1;i<=n;i++){
        cin >> weight[i];
    }
    for(int i=1;i<n;i++){
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }
    search_tree(1);
    cout << max(DP[1][0],DP[1][1]) << '\n';
    return 0;
}