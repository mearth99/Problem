#include<iostream>
#include<cstring>
using namespace std;

int v[100001];
int lst[200001];
int n, k, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> lst[i];
    int l = 0, r = 0;
    while (r < n) {
        v[lst[r]]++;
        while (v[lst[r]] > k) {
            v[lst[l]]--;
            l++;
        }
        r++;
        
        ans = max(ans, r - l);
        
    }

    if (!ans) ans = n;
    cout << ans;
}