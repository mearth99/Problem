#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 987654321
int D[1001][3];
int colors[1001][3];
int N;

//0 : 빨, 1: 초, 2: 파
int DFS(int cur, int color, int start_color){
    if(cur==N) return 0;
    if(D[cur][color]!=-1) return D[cur][color];
    int result = INF;
    for(int i=0;i<3;i++){
        if(i==color) continue;
        if(cur==N-1 && i==start_color) continue;
        result = min(result, colors[cur][i] + DFS(cur+1,i,start_color));
    }
    D[cur][color] = result;
    return D[cur][color];
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++)
            cin >> colors[i][j];
    }
    int result = INF;
    for(int i=0;i<3;i++){
        memset(D,-1,sizeof(D));
        result = min(result,DFS(1,i,i)+colors[0][i]);
    }
    cout << result;
}