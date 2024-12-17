#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
bool visit[4501];

void Addset(int opp, set<int> &me, vector<set<int>> lists, bool visit[]){
    me.insert(opp);
    for(set<int>::iterator iter=lists[opp].begin();iter!=lists[opp].end();iter++){
      Addset(*iter,me,lists,visit);
    }
}
int solution(int n, vector<vector<int>> results) {
    /*단방향으로 그래프를 그린다.
      연결되어 있는 부모와 자식 count를 비교한다.
      부모: 패배, 자식: 승리 , 부모 + 자식 = 전체라면, 순위를 특정할 수 있다.
      level을 만든다.
    */
    queue<int> q;
    vector<set<int>> parents(n+1);
    vector<set<int>> child(n+1);
    
    int answer = 0;
    q.push(results[0][0]);
    while(!q.empty()){
        int target = q.front();
        int winner, loser;
        q.pop();
        for(int i=0;i<results.size();i++){
            if(visit[i]) continue;
            if(target == results[i][0] || target == results[i][1]){
                winner = results[i][0];
                loser = results[i][1];
                child[winner].insert(loser);
                parents[loser].insert(winner);
                visit[i] = true;
                q.push(loser);
            }
        }
    }
    for(int i=1;i<=n;i++){
        set<int> temp;
        for(set<int>::iterator iter=parents[i].begin();iter!=parents[i].end();iter++){
            Addset(*iter,temp,parents,visit);
        }
        parents[i].insert(temp.begin(),temp.end());
    }
    for(int i=1;i<=n;i++){
        set<int> temp;
        for(set<int>::iterator iter=child[i].begin();iter!=child[i].end();iter++){
            Addset(*iter,temp,child,visit);
        }
        child[i].insert(temp.begin(),temp.end());
    }
    for(int i=1;i<=n;i++){
        if(parents[i].size()+child[i].size()==n-1)
            answer++;
    }
    return answer;
}