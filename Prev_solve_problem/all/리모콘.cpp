
#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
#include <cmath>
using namespace std;

int normal[10];
int N,M,max_count;

int main()
{
    fill_n(normal,10,1);
    cin >> N >> M;

    max_count = N-100;
    for(int i=0;i<M;i++){
        int error_botton;
        cin >> error_botton;
        normal[error_botton] = 0;
    }
    int get_number = 0;
    string number = to_string(N);

    for(int it =0;it<number.size();it++){
        int gap = N;
        int target = 0;
        for(int i=0;i<10;i++){
            if(!normal[i]) continue;
            if(gap > (target+i)*pow(10,number.size()-1-it)){
                gap = (target+i)*pow(10,number.size()-1-it);
                target = target*10 + i;
            }
        }
        if(target != -1)
            get_number = get_number * 10 + target; 
    }
    if(get_number!=0){
        cout << min(abs(N-get_number)+(int)number.size(),abs(N-100));
    }
    return 0;
}