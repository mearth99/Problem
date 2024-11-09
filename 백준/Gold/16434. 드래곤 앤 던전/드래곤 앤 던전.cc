#include <iostream>
#include <string>
#include <vector> 
using namespace std;
struct dungun {
    bool room;
    long long A, H;
    dungun() : room(0), A(0), H(0) {}
    dungun(bool r, long long a, long long h) : room(r), A(a), H(h) {}
};
int main() {
    ios::sync_with_stdio(0); cin.tie(0); //추가

    long long N, ATK_IT;
    cin >> N >> ATK_IT;
    vector<dungun> arr(N);
    for (auto& it : arr) {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1) it = dungun(false, b, c);
        else it = dungun(true, b, c);
    }
    long long end = 1e18;
    long long start = 1; //0에서 1로 변경
    while (start < end) {
        long long MaxHp = start + (end - start) / 2;
        long long curHp = MaxHp;
        long long curATK = ATK_IT;
        bool flag = false;
        for (auto& it : arr) {
            if (!it.room) {
                long long cnt = (it.H + curATK - 1) / curATK;
                if (curHp <= (cnt - 1) * it.A) { //수정
                    start = MaxHp + 1;
                    flag = true;
                    break;
                }
                curHp -= (cnt - 1) * it.A; //수정
            }
            else {
                curATK += it.A;
                curHp = min(MaxHp, curHp + it.H);
            }
        }
        if (!flag)
            end = MaxHp;
    }
    cout << end;
    return 0;
}