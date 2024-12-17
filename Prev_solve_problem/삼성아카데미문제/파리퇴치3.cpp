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
int dy[8] = {0,0,-1,1,-1,1,-1,1};
int dx[8] = {-1,1,0,0,-1,1,1,-1};

int N,M;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
  	cin.tie(NULL);
	cout.tie(NULL);	
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		int output = 0;
		cin >> N >> M;
		arr.resize(N,vector<int>(N));
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cin >> arr[i][j];
			}
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				int sum = arr[i][j];
				for(int k=0;k<4;k++){
					int count = 1;
					int y = i;
					int x = j;
					while(count < M){
						int ny = y + dy[k];
						int nx = x + dx[k];
						if(ny>=0 && ny < N && nx>=0 && nx<N){
							sum += arr[ny][nx];
							y = ny;
							x = nx;
						}
						count++;
					}
				}
				output = max(output, sum);
				sum = arr[i][j];
				for(int k=4;k<8;k++){
					int count = 1;
					int y = i;
					int x = j;
					while(count < M){
						int ny = y + dy[k];
						int nx = x + dx[k];
						if(ny>=0 && ny < N && nx>=0 && nx<N){
							sum += arr[ny][nx];
							y = ny;
							x = nx;
						}
						count++;
					}
				}
				output = max(output, sum);
			}
			
		}
		outputs.push_back(output);
		arr.clear();
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}