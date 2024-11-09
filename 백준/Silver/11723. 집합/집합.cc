#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;


int S=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M;
    cin >> M;
    for(int i=0;i<M;i++){
        string command;
        int cur;
        cin >> command;
        if(command =="add"){
            cin >> cur;
            S = S | (1<<cur);
        }
        if(command =="remove"){
            cin >> cur;
            S = S & ~(1<<cur);
        }
        if(command =="check"){
            cin >> cur;
            if(S&(1<<cur)) cout << "1" << '\n';
            else cout << "0" << '\n';
        }
        if(command =="toggle"){
            cin >> cur;
            S = S ^ (1<<cur);
        }
        if(command =="all"){
           S=(1<<21)-1;
        }
        if(command =="empty"){
            S=0;
        }

    }
    return 0;
}