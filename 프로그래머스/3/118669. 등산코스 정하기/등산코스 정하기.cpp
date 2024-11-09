#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string.h>
#define INF 2000000
using namespace std;

/*
모든 녀석들을 돌면서 intensity가 최소한인 녀석을 찾아 output에 넣어야 한다.
이때, cost가 높은 경우라도 intensity가 최소 일 수 있으니 더 탐사해야한다.
같은 Node에서 intensity가 더 작지 않다면, 추가로 탐사할 필요가 없다.
*/
vector<pair<int,int>> arr[50001];
int node[50001];
vector<pair<int,int>> output;

bool cmp(pair<int,int> p1 , pair<int,int> p2){
    if(p1.second==p2.second)
        return p1.first < p2.first;
    else
        return p1.second < p2.second;
}
void di(int n,vector<int> gates,vector<int> summits){
    memset(node,-1, sizeof(node));
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    for(auto it : gates){
        q.push({0,it});
        node[it] = 0;
    }
    while(!q.empty()){
        int cost = q.top().first;
        int cur = q.top().second;
        q.pop();

        if(find(summits.begin(),summits.end(),cur)!=summits.end()){
            int top = *find(summits.begin(),summits.end(),cur);
            output.push_back({top,cost});
            continue;
        }
        if(cost>node[cur]) continue;
        for(auto it : arr[cur]){
            int nextcur = it.first;
            int nextcost = it.second;
            if(node[nextcur]==-1 || max(cost, nextcost) < node[nextcur]){
                node[nextcur] = max(cost, nextcost);
                q.push({node[nextcur],nextcur});
            }
        }
    }
    sort(output.begin(),output.end(),cmp);
    return;
}
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    for(auto it: paths){
        arr[it[0]].push_back({it[1],it[2]});
        arr[it[1]].push_back({it[0],it[2]});
    }
    di(n,gates,summits);
    return {output[0].first,output[0].second};
}