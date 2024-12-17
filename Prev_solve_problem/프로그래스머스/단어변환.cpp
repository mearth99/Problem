#include <string>
#include <vector>
#include <queue>
using namespace std;
bool visit[51];

int solution(string begin, string target, vector<string> words) {
    int answer = 99999;
    
    queue<pair<string,int>> q;
    
    q.push(make_pair(begin,0));
    while(!q.empty()){
        string current = q.front().first;
        int count = q.front().second;
        q.pop();
        if(current.compare(target)==0){
            answer = answer > count ? count : answer;
            continue;
        }
        for(int i=0;i<words.size();i++){
            int match = 0;
            if(visit[i]) continue;
            for(int j=0;j<current.size();j++){
                if(current.at(j)==words[i][j])
                    match++;
            }
            if(match==current.size()-1){
                visit[i] = true;
                q.push(make_pair(words[i],count+1));
            }
        }
        
    }
    if(answer == 99999) return 0;
    return answer;
}