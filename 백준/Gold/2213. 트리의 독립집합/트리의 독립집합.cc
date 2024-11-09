#include<vector>
#include<algorithm>
#include<queue>
#include<iostream>
#include<cstring>
using namespace std;

vector<int> output;
vector<int> tree[10001];
bool visit[10001];
int weight[10001];
int DP[10001][2];

void search_tree(int node){
    visit[node] = true;
    DP[node][0] = 0; //포함안될때
    DP[node][1] = weight[node]; //포함
    for(auto it : tree[node])
        if(!visit[it]){  
            search_tree(it);
            DP[node][0] += max(DP[it][0],DP[it][1]);
            DP[node][1] += DP[it][0];
        }
    return;
}
void print_tree(int node, int parent){
    if(DP[node][0] < DP[node][1] && !visit[parent]){
        output.push_back(node);
        visit[node] = true;
    }
    for(auto it : tree[node])
        if(it != parent)
            print_tree(it, node);
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;   
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> weight[i];
    
    for(int i=1;i<n;i++){
        int from, to;
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }
    search_tree(1);
    memset(visit,false,sizeof(visit));
    print_tree(1,1);
    sort(output.begin(),output.end());
    cout << max(DP[1][0],DP[1][1]) << '\n';
    for(int i=0;i<output.size();i++)
        cout << output[i] << ' ';
    return 0;
}