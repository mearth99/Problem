#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 987654321
int D[2001][2001];
int music[2001];
int N;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    memset(D,0x7f,sizeof(D));
    for(int i=1;i<=N;i++){
        cin >> music[i];
    }
    D[0][1] = D[1][0] = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) continue; //둘이 같은 노래를 선점하는건 존재하지 않는다.
            int next_music = max(i,j) +1; //다음 노래는 i와 j가 부른 최신의 노래 중 가장 큰 값의 +1이다.
            if(next_music>N) continue;
            if(i==0 || j ==0)
                music[0] = music[next_music];
            D[next_music][j] = min(D[next_music][j], D[i][j] + abs(music[i]-music[next_music]));
            D[i][next_music] = min(D[i][next_music], D[i][j] + abs(music[j]-music[next_music]));
        }
    }
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            cout << D[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}