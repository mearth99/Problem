#include <stdio.h>

int main() {
   int card[100] = {0};
   int n,m,max=1;
   scanf("%d%d",&n,&m);
   for(int i=0;i<n;i++)
   {
       int input;
       scanf("%d",&input);
       card[i]=input;
   }
   
   
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           if(i==j)
            j++;
           for(int k=0;k<n;k++)
         {
             if(i==k || j==k)
                k++;
                if(card[i]+card[j]+card[k]<=m && card[i]+card[j]+card[k]>max)
                max = card[i]+card[j]+card[k];
         }
       }
   }
   
   printf("%d",max);
   
   return 0;
   
}