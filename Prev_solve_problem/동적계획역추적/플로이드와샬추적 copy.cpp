#include <string.h>
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[105][105];
int nxt[105][105];
int n, m;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    fill(d[i], d[i]+1+n, INF);
  while(m--){
    int a,b,c;
    cin >> a >> b >> c;
    d[a][b] = min(d[a][b], c);
    nxt[a][b] = b;
  }
  for(int i = 1; i <= n; i++) d[i][i] = 0;

  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        if(d[i][k] + d[k][j] < d[i][j]){
          d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
          nxt[i][j] = nxt[i][k];
        }
    return 0;
}