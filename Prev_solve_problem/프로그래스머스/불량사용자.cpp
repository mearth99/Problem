#include <string>
#include <vector>
#include <set>
using namespace std;

vector<set<string>> ban_list;
vector<string> user;
vector<string> ban;
bool visit[8];
bool S_compare(string user, string ban){
    if(user.size()!=ban.size()) return false;
    for(int i=0;i<user.size();i++){
        if(ban[i]=='*') continue;
        if(user[i]!=ban[i])
            return false;
    }
    return true;
}
void DFS(int index, set<string> s){
    if(index == ban.size()){
        ban_list.push_back(s);
        return;
    }
    for(int i=0;i<user.size();i++){
        if(!visit[i] && S_compare(user[i],ban[index])){
            set<string> other_s = s;
            other_s.insert(user[i]);
            visit[i] = true;
            DFS(index+1,other_s);
            visit[i] = false;
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    user = user_id;
    ban = banned_id;
    set<string> s;
    DFS(0,s);
    return ban_list.size();
}