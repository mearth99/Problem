#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

vector<pair<int,int>> outputs;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
  	cin.tie(NULL);
	cout.tie(NULL);	
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		int N,M,c1,c2,C;
        cin >> N >> M;
        vector<int> arr1(N);
        vector<int> arr2(M);
        cin >> c1 >> c2;
        C= abs(c1-c2);
        int minv = 99999999;
        int min_cnt = 0;
        for(int i=0;i<N;i++) cin >> arr1[i];
        for(int i=0;i<M;i++) cin >> arr2[i];
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        if(N>=M){
            for(int i=0;i<N;i++){
                int v = abs(arr1[i] - *lower_bound(arr2.begin(),arr2.end(),arr1[i])) + C;
                if(v<minv){
                    minv = v;
                    min_cnt = 1;
                }else if(v==minv)
                    min_cnt++;
            }
        }else{
            for(int i=0;i<M;i++){
                int v = abs(arr2[i] - *lower_bound(arr1.begin(),arr1.end(),arr2[i])) + C;
                if(v<minv){
                    minv = v;
                    min_cnt = 1;
                }else if(v==minv)
                    min_cnt++;
            }
        }
        outputs.push_back({minv,min_cnt});
        arr1.clear();
        arr2.clear();
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it.first << ' ' << it.second << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}