#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> antana(n);
    for(int i=0;i<n;i++){
        cin >> antana[i];
    }
    sort(antana.begin(),antana.end());
    cout << antana[(n-1)/2];
    return 0;
}