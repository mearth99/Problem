#include <string>
#include <vector>
#include <map>
#include <functional>
using namespace std;
int maxlen;
map<string, std::function<int(int)>> dictF ={
    {"next", [](int v){return v+10 > maxlen ? maxlen : v+10; }},
    {"prev", [](int v){return v-10 > 0 ? v-10 : 0;}}
};


int str_to_time(string t){
    int minute = stoi(t.substr(0,2));
    int second = stoi(t.substr(3,4));
    return minute * 60 + second;
}

string time_to_str(int v){
    int minute = v/60;
    int second = v%60;
    string sminute = minute < 10 ? '0' + to_string(minute) : to_string(minute);
    string ssecond = second < 10 ? '0' + to_string(second) : to_string(second); 
    return  sminute + ':' + ssecond;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int ipos = str_to_time(pos);
    int ops = str_to_time(op_start);
    int ope = str_to_time(op_end);
    maxlen = str_to_time(video_len);
    for(auto it : commands){
        if(ipos >= ops && ipos <= ope) ipos = ope;
        ipos = dictF[it](ipos);
        if(ipos >= ops && ipos <= ope) ipos = ope;    
    }
    return time_to_str(ipos);
}