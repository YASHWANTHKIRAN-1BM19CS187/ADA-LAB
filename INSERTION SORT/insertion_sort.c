#include <stdio.h>
#include <time.h>
#include<stdlib.h>
void main(){

   int i, j, count, temp, number[25];
    clock_t start;
   printf("enter no. of values to generate random: ");
   scanf("%d",&count);

  
   for(i=0;i<count;i++)
      number[i]=rand()%100 +1;
    
    start=clock();
   for(i=1;i<count;i++){
      temp=number[i];
      j=i-1;
      while((temp<number[j])&&(j>=0)){
         number[j+1]=number[j];
         j=j-1;
      }
      number[j+1]=temp;
   }
    start=clock()-start;
    double t=((double)start)/CLOCKS_PER_SEC;
   printf("Order of Sorted elements using insertion sort: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);
          printf("\n time : %.8f\n",t);
          
    
}