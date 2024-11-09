#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int>> pos;

int sol(){
    int a = pos[0].first, b = pos[0].second;
	int c = pos[1].first, d = pos[1].second;
	int e = pos[2].first, f = pos[2].second;

    return (a*d+c*f+e*b-c*b-e*d-a*f)/2;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i=0;i<3;i++){
        int x,y;
        cin >> x >> y;
        pos.push_back({x,y});
    }
    int out = sol();
    if(out>1)
        cout << "1";
    else if(out==0)
        cout << "0";
    else
        cout << "-1";
    return 0;
}