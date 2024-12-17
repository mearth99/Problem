#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>

#define INF 20000000
using namespace std;

vector<int> outputs;
struct road{
	int start, end, value;
};


int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		int v,e,minv=INF;
		cin >> v >> e;
		vector<vector<int>> city(v+1,vector<int>(v+1,INF));
		vector<bool> visited(v+1);
		for(int i=0;i<e;i++){
			int from,to,cost;
			cin >> from >> to >> cost;
			city[from][to] = cost;
		}
		for(int k=1;k<=v;k++){
			for(int i=1;i<=v;i++){
				for(int j=1;j<=v;j++){
					city[i][j] = min(city[i][j],city[i][k]+city[k][j]);
				}
			}
		}
		for(int i=1;i<=v;i++){
			minv = min(minv,city[i][i]);
		}
		if(minv==INF)
			outputs.push_back(-1);
		else
			outputs.push_back(minv);
	}
	int a = 1;
	for(int i=0;i<outputs.size()-1;i++){
		cout << '#' << a++ << ' ' << outputs[i] << '\n';
	}
	cout << '#' << a++ << ' ' << outputs.back();

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}