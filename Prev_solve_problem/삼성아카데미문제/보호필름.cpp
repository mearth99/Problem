#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

vector<int> outputs;
vector<vector<int>> arr;
vector<vector<int>> T_arr;
int D, W, K,output;

vector<bool> visited;
/*
1. 성능검사
2. 줄변경
3. 값확인
*/
void check_T(bool flag, int line, int value){
	if(flag){
		for(int i=0;i<W;i++){
			T_arr[line][i] = value;
		}
	}else{
		for(int i=0;i<W;i++){
			T_arr[line][i] = arr[line][i];
		}
	}
}

void DFS(int cur, int cnt){
	bool around_flag = true;
	int t, t_cnt;
	for(int i=0;i<W;i++){
		t=-1, t_cnt = 0;
		bool flag = false;
		for(int j=0;j<D;j++){
			if(T_arr[j][i]==1){
				if(t==1) t_cnt++;
				else{
					t=1, t_cnt = 1;
				}
			}else{
				if(t==0) t_cnt++;
				else{	
					t=0, t_cnt = 1;
				}
			}
			if(t_cnt >= K){
				flag = true;
				break;
			}
		}
		if(!flag){
			around_flag = false;
			break;
		}
	}
	if(around_flag){
		output = min(output,cnt);
		return;
	}else{
		for(int i=cur;i<D;i++){
			if(visited[i]) continue;
				visited[i] = true;
				check_T(true, cur, 0);
				DFS(cur,cnt+1);
				check_T(false,cur, 0);
				check_T(true, cur, 1);
				DFS(cur,cnt+1);
				check_T(false,cur, 0);
				visited[i] = false;
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
		output = 987564321;
		cin >> D >> W >> K;
		
		visited.clear();
		visited.resize(D,false);
		arr.clear();
		arr.resize(D,vector<int>(W));
		for(int i=0;i<D;i++){
			for(int j=0;j<W;j++)
				cin >> arr[i][j];
		}
		T_arr.clear();
		T_arr.assign(arr.begin(),arr.end());
		DFS(0,0);
		outputs.push_back(output);
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}