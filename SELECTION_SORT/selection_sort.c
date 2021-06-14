#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void main(){
    
   int i, j, count, temp, number[25];
    clock_t start;
   printf("enter no . of values to generate random: ");
   scanf("%d",&count);

    for(i=0;i<count;i++)
      number[i]=rand()%100 +1;
      
      start=clock();
   for(i=0;i<count;i++){
      for(j=i+1;j<count;j++){
         if(number[i]>number[j]){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
   }
    start=clock()-start;
    double t=((double)start)/CLOCKS_PER_SEC;

   printf("Sorted elements using selection sort: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);
    printf("\n time : %.8f\n",t);

}