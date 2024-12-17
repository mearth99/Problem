#include <string>
#include <vector>

using namespace std;

struct Node{
  int val = -1;
  int prev = -1;
  int next = -1;
}

int checktable(vector<bool> table){
  int value = 0;
  for(auto i : table){
    if(!i)
      value++;
  }
  return value;
}
string solution(int n, int k, vector<string> cmd) {
    vector<bool> table(n);
    int index=0;
    string answer = "";
    for(auto text:cmd){
        switch(text.at(0)){
          case 'U':
            index -= stoi(text.substr(text.find(" ")+1,text.length()))-checktable(table);
            break;
          case 'D':
            index += stoi(text.substr(text.find(" ")+1,text.length()))+checktable(table);
            break;
          case 'C':
            break;
          case 'Z':
            break;
          default: break;
        }
    }
    return answer;
}