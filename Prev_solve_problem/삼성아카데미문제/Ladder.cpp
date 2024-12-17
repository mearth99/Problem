#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
//2, 93
vector<int> outputs;
vector<vector<int>> arr;
bool Go(int y,int x,int direct){ //direct 0:아래 1:왼쪽 2:오른쪽
	int cx=x,cy=y,cd=direct;
	while(1){
		if(arr[cy][cx]==2){
			return true;
		}
		//좌측이동
		if(cd==0 && cx-1>=0 && arr[cy][cx-1]==1){
			cx--;
			cd=1;
			continue;
		}
		//우측이동
		if(cd==0 && cx+1<100 && arr[cy][cx+1]==1){
			cx++;
			cd=2;
			continue;
		}
		//왼쪽유지
		if(cd==1 && cx-1>=0 && arr[cy][cx-1]==1){
			cx--;
			continue;
		}
		//우측유지
		if(cd==2 && cx+1<100 && arr[cy][cx+1]==1){
			cx++;
			continue;
		}
		//하강
		if(cy<99){
			cy++;
			cd=0;
			continue;
		}
		return false;
	}
	

	
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;

	for(test_case = 1; test_case <= 10; ++test_case){
		cin>>T;
		arr.clear();
		arr.resize(100,vector<int>(100));
		for(int i=0;i<100;i++){
			for(int j=0;j<100;j++){
				cin >> arr[i][j];
			}
		}
		for(int i=0;i<100;i++){
			if(arr[0][i]==1)
				if(Go(0,i,0))
					outputs.push_back(i);
		}
	}
	

	int a = 1;
	for(auto it : outputs)
		cout << '#' << a++ << ' ' << it << '\n';
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}