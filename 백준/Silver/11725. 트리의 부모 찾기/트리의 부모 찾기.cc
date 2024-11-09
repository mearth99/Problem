#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int node[100001];
bool visit[100001];
vector<int> arr[100001];
void seek_tree(int start){
    node[start] = -1;
    visit[start] = true;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto it : arr[v]){
            if(!visit[it]){
                visit[it] =true;
                node[it] = v;
                q.push(it);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    
    for(int i=0;i<n-1;i++){
        int from, to;
        cin >> from >> to;
        arr[from].push_back(to);
        arr[to].push_back(from);
    }
    seek_tree(1);
    for(int i=2;i<=n;i++)
        cout << node[i] << '\n';

    return 0;
}