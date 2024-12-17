#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <set>
using namespace std;

vector<int> outputs;

int node[101] = {0};

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
	if(a<b) node[b] = a;
	else node[a] = b;
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		int N, M;
		for(int i=0;i<101;i++) node[i] = i;
		set<int> group;
		group.clear();
		cin >> N >> M;
		for(int i=0;i<M;i++){
			int from, to;
			cin >> from >> to;
			Union_Parent(from, to);
		}
		for(int i=1;i<=N;i++){
			group.insert(Get_Parent(node[i]));
		}
		outputs.push_back(group.size());
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}