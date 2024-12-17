#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int x, int y, int n) {
    int answer = 987654321;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,x});
    while(!q.empty()){
        int count = q.top().first;
        int cur = q.top().second;
        if(cur==y){
            answer = min(answer, count);
            break;
        }
        if(cur<y){
            q.push({count+1,cur+n});    
            q.push({count+1,cur*2});    
            q.push({count+1,cur*3});    
        }
    }
    return answer;
}
int main(){
    solution(10,40,5);
    return 0;
}