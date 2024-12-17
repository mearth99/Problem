#include<iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct climb{
    int x, y, v, flag, len;
};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int N, K, output;
vector<int> outputs;
bool visited[8][8];

int DFS(int y, int x, int v, int flag, vector<vector<int>> mountain){
    visited[y][x] = true;
    int value = 0;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<N && ny >=0 && ny<N && !visited[ny][nx]){
            if(mountain[ny][nx] < v)
                value = max(value, DFS(ny,nx, mountain[ny][nx], flag, mountain)); 
            else if(mountain[ny][nx]-K < v && flag){
                value = max(value, DFS(ny,nx, v-1, false, mountain));
            }
        }
    }
    visited[y][x] = false;
    return value+1;
}


int main(int argc, char** argv)
{
    freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case;
	int T;
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int Maxv=0;
        output = 0;
        cin >> N >> K;
        vector<vector<int>> mountain(N,vector<int>(N));
        for(int i=0;i<N;i++){
        	for(int j=0;j<N;j++){
            	cin >> mountain[i][j];
            	Maxv = max(Maxv,mountain[i][j]);
            }
        }
          
        for(int i=0;i<N;i++){
        	for(int j=0;j<N;j++){
            	if(mountain[i][j]==Maxv)
                    output = max(output, DFS(i, j, mountain[i][j], true, mountain));
                    memset(visited,0,sizeof(visited));
            }
        }
        outputs.push_back(output);
        for(int i=0;i<N;i++){
            mountain[i].clear();
        }
        mountain.clear();
	}
    int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}