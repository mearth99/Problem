#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

int main(int argc, char** argv)
{

	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		char checs[8][8];
		int count = 0;
		vector<pair<int,int>> look; 
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				cin >> checs[i][j];
				
				if(checs[i][j]=='O'){ 
					count++;
					look.push_back({i,j});
				}
			}
		}
		if(count!=8) cout << '#' << test_case << ' ' << "no" << '\n';
		else{
			//행이 일치하는지, 열이 일치하는지 비교
			bool flag = false;
			for(int i=0;i<8;i++){
				if(flag) break;
				pair<int,int> target = look[i];
				for(int j=i+1;j<8;j++){
					pair<int,int> opp = look[j];
					if(target.first == opp.first || target.second == opp.second)
						flag = true;
				}
			}
			if(!flag)
				cout << '#' << test_case << ' ' << "yes" << '\n';
			else
				cout << '#' << test_case << ' ' << "no" << '\n';
		}
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}