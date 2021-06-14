#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<limits.h>

void bubble(int *a,int n)
{
    int i,j,temp;
    for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=n-1;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

void main()
{
    int min,temp,k=0;
    double t;
    clock_t start,end;
    int n[10]={100,500,1000,5000,7500,10000,25000,50000,75000,100000};
    freopen("output.txt","w",stdout);
    while(k<10)
    {
        int *a = (int*)malloc(n[k]*sizeof(int));
        for(int i=0;i<n[k];i++)
            a[i] = rand() % INT_MAX;

        start = clock();
        bubble(a,n[k]);
        end = clock();
        t=((double)(end-start))/(double)CLOCKS_PER_SEC;

        printf("Time taken for n = %d is %.5fs\n",n[k],t);
        k++;
    }
}