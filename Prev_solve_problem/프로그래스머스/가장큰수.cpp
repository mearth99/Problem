#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(string& p1, string& p2){ //566 56 565
  if(p1.front()-0==p2.front()-0){
    if(p1.length()>p2.length()){
      char maxc = *max_element(p2.begin(),p2.end());
      string temp = p2;
      while(p1.length()!=temp.length()){
        temp.push_back(maxc);
      }
    cout << p1 << " " << temp << " " << p2 << endl;
      return stoi(p1)<stoi(temp);
    }else if(p1.length()==p2.length()){
      return stoi(p1) > stoi(p2);
    }
      else{
      char maxc = *max_element(p1.begin(),p1.end());
      string temp = p1;
      while(p2.length()!=temp.length()){
        temp.push_back(maxc);
      }
    cout << p2 << " " << temp << " " << p1 << endl;

      return stoi(temp)<stoi(p1);
    }
  }
  return p1.front()-0 < p2.front()-0;
}
string solution(vector<int> numbers) {
  //앞자리가 가장 큰 숫자대로 정렬하면 된다. 글자 정렬 시, 사전 순서대로 된다고 했는데 이를 써먹으면 될 듯?
  vector<string> dict;
  string answer = "";
  for(int i=0;i<numbers.size();i++)
    dict.push_back(to_string(numbers[i]));
  sort(dict.begin(),dict.end(),cmp);
  for(int i=dict.size()-1;i>=0;i--)
    answer.append(dict[i]);
  return answer;
}