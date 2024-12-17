#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>

using namespace std;

bool compare(const pair<int,int>& p1, pair<int,int>& p2){
  if(p1.first == p2.first)
      return p1.second<p2.second;
  else
      return p1.first > p2.first;
}
bool cmp(pair<string, int>& p1, pair<string, int>& p2){
  return p1.second > p2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> sum_play;
    unordered_map<string, vector<pair<int,int>>> gen_play;
    for(int i=0;i<genres.size();i++){
      sum_play[genres[i]] += plays[i];
      gen_play[genres[i]].push_back(make_pair(plays[i],i));
    }
    vector<pair<string,int>> sum_play_vec(sum_play.begin(),sum_play.end());
    sort(sum_play_vec.begin(),sum_play_vec.end(),cmp);
    
    for(auto it=gen_play.begin();it!=gen_play.end();it++){
      sort(it->second.begin(),it->second.end(),compare);
    }
    for(auto it=sum_play_vec.begin();it!=sum_play_vec.end();it++){
        auto current = gen_play[it->first];
      for(int i=0,me=0; i<current.size()&&me<2; i++,me++)
          answer.push_back(current[i].second);
    }
    return answer;
}