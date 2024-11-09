#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 20000000

bool compare(pair<int,int> p1,pair<int,int> p2){
    return p1.second < p2.second;
}
int getParent(vector<int> &parents, int t){
    if(parents[t]==t) return t;
    return parents[t] = getParent(parents,parents[t]);
}
void unionParent(vector<int> &parents, int me, int opp){
    me = getParent(parents,me);
    opp = getParent(parents,opp);
    if(me<opp) parents[opp] = me;
    else parents[me] = opp;
}

int main()
{
    int n,m,one,two,sum,maxv=INF,minv=0,count=0;
    cin >> n >> m;
    vector<vector<int>> committee(n+1,vector<int>(n+1,INF));
    vector<int> parents(n+1);
    vector<int> subcommittee;
    vector<int> print;
    for(int i=1;i<=n;i++){
        parents[i] = i;
        committee[i][i] = 0;
    }
    for(int i=0;i<m;i++){
        cin >> one >> two;
        unionParent(parents,one,two);
        committee[one][two]=1;
        committee[two][one]=1;
    }
    for(int i=1;i<=n;i++)
        getParent(parents,i);

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                committee[i][j] = min(committee[i][j], committee[i][k]+committee[k][j]);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(parents[j]==i){
                subcommittee.push_back(j);
            }
        }
        int president=0;
        if(subcommittee.size()>0){
            count++;
            maxv = INF;
            for(auto q : subcommittee){
                minv = 0;
                for(auto p : subcommittee)
                    minv = max(minv,committee[q][p]);
                if(minv<maxv){
                    maxv = minv;
                    president = q;
                }
            }
            print.push_back(president);
            subcommittee.clear();
        }
    }
    sort(print.begin(),print.end());
    cout << count << endl;
    for(auto p : print)
        cout << p << endl;
    return 0;
}