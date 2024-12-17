#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

struct exercise{
	int from, to, cost;
};


bool cmp(exercise &p1, exercise &p2){
	return p1.cost > p2.cost;
}


vector<int> outputs;
int N, M;
vector<exercise> graph; 
vector<int> node;


int Get_Parent(int x){
	if(node[x]==x) return x;
	else return node[x] = Get_Parent(node[x]);
}
bool Find_Parent(int a, int b){
	a = Get_Parent(a);
	b = Get_Parent(b);
	if(a==b) return true;
	else return false;
}
void Union_Parent(int a, int b){
	a = Get_Parent(a);
	b = Get_Parent(b);
	if(a<=b) node[b] = a;
	else node[a] = b;
}

int main(int argc, char** argv)
{
	freopen("/mnt/c/Users/dlwls/Downloads/input.txt", "r", stdin);
	freopen("/mnt/c/Users/dlwls/Downloads/myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		node.resize(401,0);
		cin >> N >> M;
		for(int i=0;i<M;i++){
			int from, to, cost;
			cin >> from >> to >> cost;
			graph.push_back({from, to, cost});
		}
		sort(graph.begin(),graph.end(),cmp);
		queue<pair<int,int>> 
	}
	int a = 0;
	for(auto it : outputs)
		cout << '#' << a++ << ' ' << it << '\n';
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}