#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long distances=4000000001;
vector<long long> output(3);
void check(int cur, vector<int> T){
    long long Target = (long long)T[cur],left=0,right=T.size()-1;
    while(left<right){
        if(left==cur) left++;
        if(right==cur) right--;
        if(left>=right) break;
        long long v = (Target + T[left] + T[right]);
        if(distances>abs(v)){
            distances = abs(v);
            output = {Target,T[left],T[right]};
        }
        if(v>=0)
            right--;
        else
            left++;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    vector<int> T;
    cin >> N;
    T.resize(N);
    for(int i=0;i<N;i++)
        cin >> T[i];
    sort(T.begin(),T.end());
    for(int i=0;i<T.size();i++)
        check(i,T);
    sort(output.begin(),output.end());
    cout << output[0] << " " << output[1] << " " << output[2];
}