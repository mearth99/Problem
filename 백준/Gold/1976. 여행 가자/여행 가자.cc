#include<iostream>
#include<algorithm>
#include<vector>
#define INF 2100000
using namespace std;

vector<vector<int>> arr(201,vector<int>(201,INF));
vector<int> course;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int n2 = n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
            if(arr[i][j]==0) arr[i][j] = INF;
        }
    }
    for(int i=0;i<=n;i++)
        arr[i][i] = 0;
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
        arr[i][j] = min(arr[i][j],arr[i][k]+arr[k][j]);
    }
    for(int i=0;i<m;i++){
        int value;
        cin >> value;
        course.push_back(value);
    }
    for(int i=0;i<m-1;i++){
        int cur = course[i];
        int next = course[i+1];
        if(arr[cur][next]==INF){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}