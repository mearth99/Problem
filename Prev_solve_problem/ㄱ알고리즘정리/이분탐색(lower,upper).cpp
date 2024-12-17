/*
    lower_bound(x)는 x가 처음 나오거나, x값이 없다면 x값보다 큰 값의 처음 위치를 반환하는 값이다.
    본래라면, 이를 알기 위해서는 O(n)의 시간이 소요되는데, 이를 log(n)으로 감소시킬 수 있다.
    upper_bound(x)는 x보다 큰 값이 처음 나오는 위치를 반환한다.
    이를 위해서 먼저 대상이 되는 배열이 오름차순으로 정렬되어 있어야한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int lower(int x, int data[]){
    int start = 0; int end = 8; //data의 길이 
    int mid;
    while(start<end){
        mid = (start + end) /2;
        if(data[mid]<x)
            start = mid+1;
        else
            end = mid;
    }
    return end;
}
int upper(int x, int data[]){
    int start = 0; int end = 8; //data의 길이 
    int mid;
    while(start<end){
        mid = (start + end) /2;
        if(data[mid]<=x)
            start = mid+1;
        else
            end = mid;
    }
    return end;
}

using namespace std;

int main(){
    /*
    algorithm 해더에 lower_bound와 upper_bound가 둘다 구현되어 있다.
    */
    int data[] = {0,5,15,35,55,65,85,100};
    int x = lower_bound(data,data+8,15)-data;
    int y = upper_bound(data,data+8,15)-data;
    cout << x << " " << y << endl;
    x = lower(15,data);
    y = upper(15,data);
    cout << x << " " << y << endl;
    return 0;   
}