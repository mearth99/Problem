#include <string>
#include <vector>
#include <queue>
using namespace std;
bool cmp(pair<int,int> &p1,pair<int,int> &p2){
  return p1.second<p2.second;
}
int solution(vector<int> food_times, long long k) {
    int answer = 0;
    long long sum = 0;
    vector<pair<int,int>> food;
    for(int i=0;i<food_times.size();i++){
      sum +=food_times[i];
      food.push_back({food_times[i],i});
    }
    sort(food.begin(),food.end());
    if(sum<=k) return -1;
    int eat_cost = 0;
    int length = food_times.size();
    for(auto it = food.begin(); it!=food.end(); it++){
      int cost = it->first;
      int rank = it->second;
      long long alltime = cost-eat_cost*length;  
      if(k-alltime>=0){
        k-=alltime;
        length--;
        eat_cost = cost;
      }else{
        k%=length;
        sort(it,food.end(),cmp);
        return (it+k)->second;
      }
    }
}