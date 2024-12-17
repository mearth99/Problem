#include <iostream>
#include <cstdlib>

using namespace std;
int main() {
    int A,B,current=0,distance=0,next=0,value=1;
    cin >> A >> B;
    if(A<B){
        current = A;
        next = A;
        while(true){
            current = next;
            next = A + value;
            if(next >= B){
                distance = distance + abs(B-current);
                break;
            }
            else
                distance = distance + abs(next-current);
            value *= -2;
        }
    } else if(A==B)
        distance = 0;
    else{
        current = A;
        next = A;
        while(true){
            current = next;
            next = A + value;
            if(next <= B){
                distance = distance + abs(B-current);
                break;
            }
            else
                distance = distance + abs(next-current);
            value *= -2;
        }
    }
    cout << distance;
    return 0;
}