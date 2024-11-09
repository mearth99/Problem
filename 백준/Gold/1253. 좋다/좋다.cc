#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;
int counts=0;

void check(int cur, vector<int> T){
    int target = T[cur],left=0,right=T.size()-1;
    while(left<right){
        if(left==cur) left++;
        if(right==cur) right--;
        if(left>=right) break;
        int v = T[left] + T[right];
        if(target<v)
            right--;
        else if(v==target){
            counts++;
            left++;
            right--;
            return;
        }
        else
            left++;
        
    }
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    vector<int> T;
    cin >> N;
    T.resize(N);
    for(int i=0;i<N;i++){
        cin >> T[i];
    }
    sort(T.begin(),T.end());
    for(int i=0;i<T.size();i++){
        check(i,T);
    }
    cout << counts;
}