#include<bits/stdc++.h>
using namespace std;
int N, M,i,j;
char arr;
bitset<51> v, u;
int main() {
    cin >> N >> M;
    for (; i < N; i++)
        for (j=0; j < M; j++) {
            cin >> arr;
            (arr == 'X') ? v[i] = u[j] = 1 : 0;
        }
    cout << max(v.flip().count()-(51-N), u.flip().count()-(51 - M));
}