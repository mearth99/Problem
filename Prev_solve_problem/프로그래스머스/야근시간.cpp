#include <string>
#include <vector>
#include <queue>
using namespace std;

//야근 피로도는 works에 대해 n만큼 감소 시키고, 그 배열에 대해 각각 제곱한 값을 더한 것이다.
//제곱에 의해 가장 큰 수가 가장 큰 피로도를 차지하기 때문에, 가장 큰 피로도를 낮춰야한다.
//총합이 n이 되도록 works의 숫자를 감소시킬 수 있다.

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int value;
    priority_queue<int> q;
    for(auto i : works) q.push(i);
    while(!q.empty()&&n--){
      value = q.top();
      q.pop();
      if(value!=1)
        q.push(value-1);
    }
    while(!q.empty()){
      answer += q.top()*q.top();
      q.pop();
    }
    return answer;
}