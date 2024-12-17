#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

int networks[201];

int getParent(int parent[], int x){
  if(parent[x]==x) return x;
  return parent[x] = getParent(parent,parent[x]);
}
void unionParent(int parent[], int a, int b){
  a = getParent(parent, a);
  b = getParent(parent, b);
  if(a<b) parent[b] = a;
  else parent[a] = b;
  return;
}

int solution(int n, vector<vector<int>> computers) {
    set<int> lists;
    for(int i=0;i<201;i++)
        networks[i] = i;
    int temp = 0;

    for(int i=0;i<computers.size();i++){
        for(int j=0;j<computers[i].size();j++){
            if(computers[i][j]){
                temp = networks[j];
                unionParent(networks,i,j); //j를 i에 합류시킨다.
                if(temp!=networks[j])
                    for(int k=0;k<computers.size();k++){
                        if(networks[k]==temp)
                            unionParent(networks,i,k);
                    }
            }
        }
    }
    for(int i=0;i<computers.size();i++){
        lists.insert(networks[i]);
    }
    return lists.size();
}