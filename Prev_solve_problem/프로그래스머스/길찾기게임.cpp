#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*
1. 트리의 깊이가 1000이하이기 때문에, level을 최대 1000개로 구성할 수 있다.
2. 트리의 높이를 기반으로 정렬한다면, level에 1000개를 넣을 수 있다.
3. 가장 높은 y를 root로 하여 level을 정의한다면, 이진트리를 구성할 수 있다.
4. 구성한 이진트리를 바탕으로, 전위, 후위순회를 통해 정답을 출력한다.
answer[0] = 전위, answer[1] = 후위
*/
vector<int> graph[10001];
vector<pair<int,int>> level[1001];
vector<vector<int>> answer(2);
bool cmp(vector<int> p1, vector<int> p2){
    return p1[1] > p2[1];
}
void DFS(int cur,int node, pair<int,int> left, pair<int,int> right){
    for(auto it: level[cur+1]){
        if(left.first<=it.first&&it.first<=left.second){
            graph[node][0]=(it.second);
            DFS(cur+1,it.second,{left.first,it.first-1},{it.first+1,left.second});
        }
        if(right.first<=it.first&&it.first<=right.second){
            graph[node][1]=(it.second);
            DFS(cur+1,it.second,{right.first,it.first-1},{it.first+1,right.second});
        }
    }
    return;
}
void FrontSearch(int n){
    answer[0].push_back(n);
    for(auto it: graph[n])
        if(it!=-1)
            FrontSearch(it);
    return;
}
void BackSearch(int n){
    for(auto it: graph[n])
        if(it!=-1)
            BackSearch(it);
    answer[1].push_back(n);
    return;
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> sortnode = nodeinfo;
    int rootnode=-1;
    for(int i=0;i<10001;i++) graph[i].resize(2,-1);
    for(int i=0;i<sortnode.size();i++)
        sortnode[i].push_back(i+1);
    sort(sortnode.begin(),sortnode.end(),cmp);
    int prev_y = sortnode[0][1];
    int l_idx = 0;
    for(auto it : sortnode){
        if(it[1]!=prev_y){
            l_idx++;
            prev_y = it[1]; 
        }
        level[l_idx].push_back({it[0],it[2]});
    }
    rootnode = level[0][0].second;
    DFS(0,rootnode,{0,level[0][0].first-1},{level[0][0].first+1,100000});
    FrontSearch(rootnode);
    BackSearch(rootnode);
    return answer;
}

int main(){
    vector<vector<int>> edges = {{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}};
    solution(edges);
    return 0;	
}