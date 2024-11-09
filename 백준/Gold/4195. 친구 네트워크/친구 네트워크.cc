#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define INF 2100000
using namespace std;

map<string,int> arr;
int value[200001];
int friend_counts[200001];
int get_parent(int x){
    if(x==value[x])
        return x;
    else
        return value[x] = get_parent(value[x]);
}

void union_parent(int a, int b){
    a = get_parent(a);
    b = get_parent(b);
    if(a<b){
        value[b] = a;
        friend_counts[a] += friend_counts[b]; 
    }
    else if(a>b){
        value[a] = b;
        friend_counts[b] += friend_counts[a];
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int F,count=0;
        arr.clear();
        for(int i=0;i<200001;i++){
            value[i] = i;
            friend_counts[i] = 1;
        }
        cin >> F;
        for(int i=0,j=0;i<F;i++){
            int target;
            string t1, t2;
            cin >> t1 >> t2;
            if(arr.count(t1)==0)
                arr[t1]=j++;
            if(arr.count(t2)==0)
                arr[t2]=j++;
            union_parent(arr[t1],arr[t2]);
            target = get_parent(arr[t1]);
            cout << friend_counts[target] << '\n';
        }   
        
    }
    return 0;
}