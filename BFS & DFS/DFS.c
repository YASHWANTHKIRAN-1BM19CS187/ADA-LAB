#include<stdio.h>
void main()
{
int a[20][20],n,i,j,st[20],tot=1,top=-1,r[20],flag;
printf("\nEnter number of vertices :");
scanf("%d",&n);
printf("\nEnter the adjacency matrix\n");
for(i=0;i<n;i++)
{
r[i]=0;
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
}
}
st[++top]=0;
r[0]=1;
while(top!=-1)
{
flag=0;
for(j=0;j<n;j++)
{
if(r[j]==0&&a[st[top]][j]==1)
{
st[++top]=j;
tot++;
r[j]=1;
flag=1;
break;
}
}
if(flag==0)
{
top=top-1;
}
}
if(tot==n)
{
printf("\nAll nodes are reachable from the origin!!");
}
else
{
printf("\nAll nodes are not reachable from the origin!!");
}
}