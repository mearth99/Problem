#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int get_time(string time){
    return stoi(time.substr(0,2))*3600+60*stoi(time.substr(3,2))+stoi(time.substr(6,2));
}
string set_time(int time){
  int h = time / 3600;
  int m = (time % 3600) / 60;
  int s = (time % 3600 % 60);
  string hour = h < 9 ? '0' + to_string(h) : to_string(h); 
  string minute = m < 9 ? '0' + to_string(m) : to_string(m); 
  string second = s < 9 ? '0' + to_string(s) : to_string(s); 
  return hour + ':' + minute + ':' + second;
}
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    vector<int> data(99*3600+59*60+60+1);
    int play = get_time(play_time);
    int adv = get_time(adv_time);
    int maxv = 0;
    int maxtime = 0;
    //구간합으로 접근해보자.
    for(auto text : logs){
      data[get_time(text.substr(0,8))] += 1;
      data[get_time(text.substr(9))] -= 1;
    }
    for(int i=1;i<play;i++)
      data[i] += data[i-1];
    for(int i=adv;i<=play-adv;i++){
      int compare = data[i] - data[i-adv];
      if(compare>maxv){
        maxv = compare;
        maxtime = i;
      }
    }
    return set_time(maxtime);
}