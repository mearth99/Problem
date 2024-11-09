#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;
int arr[6][1001];
void solution() {
    int N;
    cin >> N;
    
    for (int j = 0; j < N; j++) {
        for (int i = 1; i < 6; i++) {
            cin >> arr[i][j];
        }
    }
    int maxv = -1, idx = -1;
    for (int j = 0; j < N; j++) {
        //당사자는 당사자가 아닌 모든 사람들을 확인하면서 중복 여부를 확인한다.
        int cnt = 0;
        for (int k = 0; k < N; k++) {
            for (int i = 1; i < 6; i++) {
                if (arr[i][k] == arr[i][j]) {
                    cnt++;
                    break;
                }
            }
        }
        if (cnt > maxv) {
            maxv = cnt;
            idx = j;
        }else if(cnt == maxv && idx > j){
            idx = j;
        }
    }
    cout << idx+1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();

    return 0;
}