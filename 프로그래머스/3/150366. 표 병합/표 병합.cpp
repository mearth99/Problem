#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;
string sell[2501];
int node[2501];
vector<string> answer;

int flatPos(int r, int c) {
    return (r - 1) * 50 + c;
}

int Get_Parent(int x){
    if(node[x]==x) return x;
    else return node[x] = Get_Parent(node[x]);
}
void Union_Parent(int a, int b){
    a = Get_Parent(a);
    b = Get_Parent(b);
    if(a<b) node[b] = a; 
    else node[a] = b;  
}

void UPDATE(vector<string> cur){
    if(cur.size()==4){
        int pos = flatPos(stoi(cur[1]),stoi(cur[2]));
        string value = cur[3];
        int target = Get_Parent(pos);
        sell[target] = value;
    }else{
        string seek = cur[1],change = cur[2];
        for(int i=1;i<=2500;i++)
            if(sell[i]==seek) sell[i] = change;
    }
}
void MERGE(vector<string> cur){
    int pos1 = flatPos(stoi(cur[1]),stoi(cur[2])), pos2 = flatPos(stoi(cur[3]),stoi(cur[4])); 
    int target1 = Get_Parent(pos1), target2 = Get_Parent(pos2);
    string s1 = sell[target1], s2 = sell[target2];
    Union_Parent(pos1,pos2);
    for(int i=1;i<=2500;i++) Get_Parent(i);
    int target = Get_Parent(pos1);
    sell[pos1] = "EMPTY", sell[pos2] = "EMPTY";
    if(s1=="EMPTY")
        sell[target] = s2;
    else
        sell[target] = s1;
    return;
}
void UNMERGE(vector<string> cur){
    int pos = flatPos(stoi(cur[1]),stoi(cur[2]));
    int target = Get_Parent(pos);
    string s = sell[target];
    for(int i=1;i<=2500;i++){
        if(node[i]==target){
            node[i] = i;
            sell[i] = "EMPTY";
        }
    }
    sell[pos] = s;
    return;
}
void PRINT(vector<string> cur){
    int pos = flatPos(stoi(cur[1]),stoi(cur[2]));
    int target = Get_Parent(pos);
    answer.push_back(sell[target]);
}
vector<string> solution(vector<string> commands) {
    for(int i=0;i<2501;i++){
        node[i] = i;
        sell[i] = "EMPTY";
    }
    for(int i=0;i<commands.size();i++){
        vector<string> cur;
        string temp;
        stringstream ss(commands[i]);
        while(getline(ss,temp, ' '))
            cur.push_back(temp);
        if(cur[0]=="UPDATE")
            UPDATE(cur);
        else if(cur[0]=="MERGE")
            MERGE(cur);
        else if(cur[0]=="UNMERGE")
            UNMERGE(cur);
        else if(cur[0]=="PRINT")
            PRINT(cur);
    }
    return answer;
}