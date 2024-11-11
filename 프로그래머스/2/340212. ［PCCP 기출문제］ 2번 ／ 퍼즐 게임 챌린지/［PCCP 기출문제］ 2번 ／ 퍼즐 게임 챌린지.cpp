#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cacu(vector<int>& diffs, vector<int>& times, long long limit, int level) {
    long long cur = 0;
    for (int i = 0; i < diffs.size(); i++) {
        int d = diffs[i];
        int t = times[i];
        int pd = i > 0 ? diffs[i - 1] : 0;
        int pt = i > 0 ? times[i - 1] : 0;
        if (d <= level) {
            cur += t;
        }
        else {
            int cnt = d - level;
            cur += cnt * (t + pt) + t;
        }
        if (limit < cur) return false;
    }
    return true;
}


int solution(vector<int> diffs, vector<int> times, long long limit) {
    int minLevel = 1;
    int maxLevel = *max_element(diffs.begin(), diffs.end());

    while (minLevel < maxLevel) {
        int midLevel = (minLevel + maxLevel) >> 1;
        bool result = cacu(diffs, times, limit, midLevel);
        if (result) {
            maxLevel = midLevel;
        }
        else {
            minLevel = midLevel + 1;
        }
    }
    return minLevel;

}