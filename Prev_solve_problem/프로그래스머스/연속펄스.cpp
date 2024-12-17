#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long solution(vector<int> sequence) {
    vector<long long> q(sequence.size());
    q[0] = sequence[0];
    for(int i=1;i<sequence.size();i++){
        q[i] = q[i-1] + sequence[i]*(i%2==0 ? 1:-1);
    }
    long long vmax=*max_element(q.begin(),q.end());
    long long vmin=*min_element(q.begin(),q.end());
    long long answer = max({abs(vmax-vmin),abs(vmax),abs(vmin)});
    return answer;
}