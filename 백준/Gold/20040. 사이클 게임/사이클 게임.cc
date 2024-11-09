#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define INF 2100000
using namespace std;

int arr[500001];
int get_parent(int x){
    if(x==arr[x])
        return x;
    else
        return arr[x] = get_parent(arr[x]);
}
void union_parent(int a, int b){
    a = get_parent(a);
    b = get_parent(b);
    if(a<b)
        arr[b] = a;
    else 
        arr[a] = b;
    return;
}
bool find_parent(int a, int b){
    a = get_parent(a);
    b = get_parent(b);
    if(a==b) return true;
    else return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,target=0;
    cin >> n >> m;
    for(int i=0;i<=n;i++)
        arr[i] = i;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        if(target==0){
            if(!find_parent(a,b)){
                union_parent(a,b);
            }else{
                target=i+1;
            }
        }
    }
    if(target)
        cout << target;
    else
        cout << '0';
    return 0;
}