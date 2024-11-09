#include<iostream>
using namespace std;
int main() {
    int T;
    cin >> T;

    while (T--) {
        int left, right, v;
        cin >> left >> right >> v;

        int st = (v - left) * 2;
        int en = (right - v - 1) * 2 + 1;
        int output = st < en ? st : en;

        printf("%d\n", output + 1);
    }
}
