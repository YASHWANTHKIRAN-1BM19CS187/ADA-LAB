#include<stdio.h>
void main()
{
int a[20][20],add[20],f[20][20],min,posx,posy,i,j,k,n,tot,flag=0,weight=0;
tot=0;
printf("\nEnter the value of n:");
scanf("%d",&n);
printf("\nEnter the adjacency matrix\n");
for(i=0;i<n;i++)
{
add[i]=0;
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
f[i][j]=0;
}
}
add[0]=1;
while(flag==0)
{
flag=1;
min=9999;
for(i=0;i<n;i++)
{
if(add[i]==1)
{
for(j=0;j<n;j++)
{
if(add[j]==0&&a[i][j]!=0&&a[i][j]<min)
{
min=a[i][j];
posx=i;
posy=j;
}
}
}
}
if(min!=9999)
{
f[posx][posy]=min;
f[posy][posx]=min;
weight=weight+f[posx][posy];
tot++;
flag=0;
add[posx]=1;
add[posy]=1;
}
}
if(tot!=n-1)
{
printf("\nMinimum spannin does not exist!!");
}
else
{
printf("\nMinimum spanning tree with weight=%d is ",weight);
for(i=0;i<n;i++)
{
printf("\n");
for(j=0;j<n;j++)
{
printf("%d ",f[i][j]);
}
}
}
}