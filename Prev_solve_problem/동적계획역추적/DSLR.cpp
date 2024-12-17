/*
입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

bool visit[10000] = {0};
pair<int,char> value[10001];

void BFS(int start, int end){
    queue<int> q;
    q.push(start);
    visit[start] = true;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(cur==end) 
            break;
        //D
        int next = cur *2;
        if(next>9999) next = next%10000;
        if(!visit[next]){
            q.push(next);
            visit[next] = true;
            value[next] = {cur,'D'}; 
        }
        next = cur -1;
        if(next<0) next = 9999;
        //S
        if(!visit[next]){
            q.push(next);
            visit[next] = true;
            value[next] = {cur,'S'}; 
        }
        next = (cur % 1000) * 10 + (cur / 1000);
        //L
        if(!visit[next]){
            q.push(next);
            visit[next] = true;
            value[next] = {cur,'L'};
        }
        next = (cur % 10) * 1000 + (cur / 10);
        //R
        if(!visit[next]){
            q.push(next);
            visit[next] = true;
            value[next] = {cur,'R'};
        }
    }
    int target = end;
    while(target!=start){
        cout << value[target].second;
        target = value[target].first;
    }
    cout << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T-->0){
        int A,B;
        cin >> A >> B;
        BFS(A,B);
        for(int i=0;i<10001;i++){
            visit[i] = 0;
            value[i].first = 0;
            value[i].second = 0;
        }
    }
    return 0;
}