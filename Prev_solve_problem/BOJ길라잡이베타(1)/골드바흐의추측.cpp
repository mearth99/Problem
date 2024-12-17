#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <vector>
#include <cmath>
using namespace std;

bool numberlist[1000001];

int main()
{
  int temp;
  int sizes = sqrt(100000);
  for(int i=2;i*i<=sizes;i++){
    if(!numberlist[i]){
      for(int j=i*i;j<=sizes;j+=i){
        numberlist[j] = true; 
      }
    }
  }
  while(1){
    bool output;
    scanf("%d",&temp);
    if(temp==0)
      break;
    for(int i=3;i<temp;i+=2){ 
      int opp = temp - i;
      if(!numberlist[opp]&&!numberlist[i]){
        output = true;
        cout << temp << " = " << i << " + " << opp << "\n";
        break;
      }
    }
    if (!output) cout << "Goldbach's conjecture is wrong\n";
  }
}