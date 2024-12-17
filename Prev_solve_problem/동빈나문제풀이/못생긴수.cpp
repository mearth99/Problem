#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

bool space[1000000] = {0};
int main(){

    int n;
    cin >> n;
    space[1] = true;
    for(int i=1,count=0;i<100000;i++){
        if(space[i]==true){
            space[i*2] = true;
            space[i*3] = true;
            space[i*5] = true;
            count++;
        }
        if(count==n){
            cout << i;
            break;
        }
    }
    return 0;
}