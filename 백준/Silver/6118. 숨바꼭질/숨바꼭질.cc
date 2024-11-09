
#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int N,M;
vector<int> arr[20001];
int visited[20001] = {0};
pair<int,int> output; // 노드번호, 긴횟수
int output_cnt = 0;
void BFS(){
    queue<pair<int,int>> q;
    q.push({1,0});
    while(!q.empty()){
        int cur = q.front().first;
        int count = q.front().second;
        if(count > output.second){
            output.first = cur;
            output.second = count;
            output_cnt = 1;
        }else if(count == output.second && cur < output.first){
            output.first = cur;
            output_cnt++;
        }else if(count == output.second){
            output_cnt++;
        }
        q.pop();
        for(auto it: arr[cur]){
            if(visited[it]) continue;
            visited[it] = 1;
            q.push({it,count+1});
        }    
    }
    
}

int main()
{
    output = {1,0};
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int from, to;
        cin >> from >> to;
        arr[from].push_back(to);
        arr[to].push_back(from);
    }
    visited[1] = 1;
    BFS();
    cout << output.first << " " << output.second << " " << output_cnt;
    return 0;
}