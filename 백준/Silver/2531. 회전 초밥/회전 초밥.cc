#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;



int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,d,k,c,food=0,output=0;
    vector<int> T;
    vector<int> search(3001); 
    cin >> N >> d >> k >> c;
    T.resize(N);
    for(int i=0;i<N;i++)
        cin >> T[i];
    for(int i=0;i<k;i++){
        int cur = T[i];
        search[cur]++;
        if(search[cur]==1) food++;
    }
    if(search[c]==0) output = food+1;
    else output = food;
    for(int i=k;i<N;i++){
        int cur = T[i];
        int pre = T[i-k];
        search[cur]++;
        search[pre]--;
        if(search[cur]==1&&cur!=pre) food++;
        if(search[pre]==0) food--;
        if(search[c]==0) output = max(output,food+1);
        else output = max(output,food);
    }
    for(int i=0;i<k;i++){
        int cur = T[i];
        int pre = T[N+i-k];
        search[cur]++;
        search[pre]--;
        if(search[cur]==1) food++;
        if(search[pre]==0) food--;
        if(search[c]==0) output = max(output,food+1);
        else output = max(output,food);
    }
    cout << output;
    
}