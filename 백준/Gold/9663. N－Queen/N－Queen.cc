#include <stdio.h>
#include <stdlib.h>
int array[15] = {0};
int correct = 0;
int N;

int next_check(int current)
{
   for(int k=0;k<current;k++)
   {
       if(array[current]==array[k])
        return 0;
       if(abs(current-k) ==abs(array[current]-array[k]))
        return 0;
   }
    return 1;
}
void N_Queen(int index)
{
    if(index ==N)
    {
        correct++;
        return;
    }
    for(int k=0;k<N;k++)
    {
        array[index] = k;
        if(next_check(index)==1)
        {
            N_Queen(index+1);
        }
    }
       
    
}

int main() {
    scanf("%d",&N);
    N_Queen(0);
    printf("%d",correct);
    
}