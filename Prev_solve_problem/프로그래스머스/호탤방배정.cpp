#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<long long,long long> rooms;

long long Find_Parent(long long number){
  if(rooms[number]==0) return number;
  else return rooms[number] = Find_Parent(rooms[number]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(auto n:room_number){
      if(rooms[n]==0){
        answer.push_back(n);
        rooms[n] = Find_Parent(n+1);
      }
      else{
        long long empty = Find_Parent(rooms[n]);
        answer.push_back(empty);
        rooms[empty] = Find_Parent(empty+1); 
      }
    }
    
    return answer;
}