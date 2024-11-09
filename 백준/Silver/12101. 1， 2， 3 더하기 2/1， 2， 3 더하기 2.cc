#include <iostream>
#include<cmath>
#include<map>
#include<string>
using namespace std;
map<string,int> a;
int arr[3] = {1,2,3};
void Sol(string s, int n, int cur){
    for(int i=0;i<3;i++){
        cur += arr[i];
        if(cur>n) continue;
        else if(cur==n) a[s+to_string(arr[i])]++;
        else Sol(s+to_string(arr[i])+"+",n,cur);
        cur -= arr[i];
    }
    return;
}
int main()
{
    int n,k,count=0;
    cin >> n >> k;
    Sol("",n,0);
    if(a.size()<k) cout << -1;
    else
        for(auto it: a){
            count++;
            if(count==k) cout << it.first;
        }
    return 0;   
}
