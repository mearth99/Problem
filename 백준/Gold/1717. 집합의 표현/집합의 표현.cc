#include<iostream>
#include<vector>

using namespace std;

vector<int> arr;
int get_parent(int x){
    if(arr[x]==x) return x;
    else return arr[x] = get_parent(arr[x]);
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
void find_parent(int a, int b){
    a = get_parent(a);
    b = get_parent(b);
    if(a==b)
        cout << "YES\n";
    else
        cout << "NO\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    arr.resize(n+1);
    for(int i=0;i<=n;i++)
        arr[i] = i;
    while(m--){
        int v,a,b;
        cin >> v >> a >> b;
        if(v==0)
            union_parent(a,b);
        else
            find_parent(a,b);
    }
    return 0;
}