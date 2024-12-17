#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 987654321
int N,K;
int D[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for(int i=0;i<N;++i){
        D[i][0] = 1;
        D[i][1] = i;
    }
}