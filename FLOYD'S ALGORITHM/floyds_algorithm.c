#include<stdio.h>
void main()
{
int i,j,k,a[20][20],n;
printf("\nEnter the value of n: ");
scanf("%d",&n);
printf("\nEnter the adjacency matrix\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
}
}
for(k=0;k<n;k++)
{
for(j=0;j<n;j++)
{
for(i=0;i<n;i++)
{
a[i][j]=a[i][j]<(a[i][k]+a[k][j])?a[i][j]:(a[i][k]+a[k][j]);
}
}
}
printf("\nFloyd's shortest path is ");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%c%d",j==0?'\n':' ',a[i][j]);
}
}
}