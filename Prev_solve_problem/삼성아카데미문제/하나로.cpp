#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

vector<long double> outputs;
vector<bool> visited;
vector<vector<long double>> arr;

long double costs = 0;
int N;
void Prim(int start){
  priority_queue<pair<long double,int>,vector<pair<long double,int>>,greater<pair<long double,int>>> q;
  q.push({0,start});
  while(!q.empty()){
    long double cost = q.top().first;
    int target = q.top().second;
    q.pop();
    if(!visited[target]){
      visited[target] = true;
      costs += cost;
      for(int i=0;i<N;i++){
        if(!visited[i])
          q.push({arr[target][i],i});
      }
    }
  }
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		costs = 0;
		double E;
		cin >> N;
		vector<pair<int,int>> island(N);
		visited.resize(N,false);
		arr.resize(N,vector<long double>(N));
		for(int i=0;i<N;i++){
			cin >> island[i].first;
		}
		for(int i=0;i<N;i++){
			cin >> island[i].second;
		}
		cin >> E;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				arr[i][j] = (pow((island[i].first - island[j].first),2) + pow((island[i].second - island[j].second),2))*E;
			}
		}
		Prim(0);
		outputs.push_back(round(costs));
		island.clear();
		visited.clear();
		for(int i=0;i<N;i++) arr[i].clear();
		arr.clear();
	}
	int a = 1;
	cout << fixed;
	cout.precision(0);
	for(int i=0;i<outputs.size();i++){
		if(i!=outputs.size()-1)
			cout << '#' << a++ << ' ' << outputs[i] << '\n';
		else
			cout << '#' << a++ << ' ' << outputs[i];
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}