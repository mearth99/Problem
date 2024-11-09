#include <stdio.h>

void Swap(int array[], int x, int y)
{
    int temp = array[x];
    array[x] = array[y];
    array[y] = temp;
    return;
}


int main() {
    int input, number;
    int array[1000];
    scanf("%d", &input);
    for(int i=0;i<input;i++)
    {
        scanf("%d", &array[i]);
    }
    for(int i=0;i<input;i++)  
    {
        for(int j=i+1;j<input;j++)
        {
            if(array[i]>array[j])
                Swap(array,i,j);
        }
    }
    
    for(int i=0;i<input-1;i++)
        printf("%d\n",array[i]);
      printf("%d",array[input-1]);
    return 0;
}