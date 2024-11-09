#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int>> pos;

long double sol(int i, int j){
    long double a = pos[0].first, b = pos[0].second;
	long double c = pos[i].first, d = pos[i].second;
	long double e = pos[j].first, f = pos[j].second;

    return (a*d+c*f+e*b-c*b-e*d-a*f)/2;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        pos.push_back({x,y});
    }
    long double out = 0.0;
    for(int i=1;i<n-1;i++){
        out += sol(i,i+1);
    }
    cout << fixed;
	cout.precision(1);
    cout << abs(out);
    return 0;
}