#include <bits/stdc++.h>
using namespace std;



void solution(){
	int N, K;
    int maxv = 0;
    int start = 0, end =0;
    cin >> N >> K;
    vector<int> arr(N);
    int dupe[100001] = {0};
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    while(end<N){
        if(dupe[arr[end]]<K){
            dupe[arr[end]]++;
            end++;
        }
        else{
            dupe[arr[start]]--;
            start++;
        }
        maxv = max(maxv,end-start);
    }

     
    cout << maxv;
   
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}