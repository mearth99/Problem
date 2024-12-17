#include <bits/stdc++.h>
using namespace std;

int cacu(int start, int end, int first,int second){
    if(end<=first) return second - first;
    if(start >= second) return second - first;
    if(end<=second){
        if(start < first) return first - start + second - end;
        else return second - end + start - first;
    }else{
        if(start < first) return 0;
        else return start - first;
    }
}

void solution(){
	int N, K;
    int start =0, end = 0;
    cin >> N >> K;
    vector<pair<int,int>> arr(N);
    for(int i=0;i<N;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    while(end<1000001){
        int sum = 0;
        for(int i=0;i<N;i++)
           sum += cacu(start, end, arr[i].first,arr[i].second);
        
        if(sum<K)
            end++;
        else if(sum==K) 
            break;
        else
            start++;
    }
    if(end==1000001) cout << "0 0";
    else cout << start << " " << end;
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}