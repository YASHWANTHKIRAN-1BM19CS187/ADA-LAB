#include <stdio.h>
#include <conio.h>
int a[10][10],n,indegre[10];
void findindeg()
{
    int i,j,s;
    for(j=0;j<n;j++)
    {
        s=0;
        for(i=0;i<n;i++)
        s+=a[i][j];
        indegre[j]=s;
    }
}
void topology()
{
    int i,u,v,t[10],s[10],top=-1,k=0;
    findindeg();
    for(i=0;i<n;i++)
    {
    if(indegre[i]==0) s[++top]=i;
    }
    while(top!=-1)
    {
    u=s[top--];
    t[k++]=u;
    for(v=0;v<n;v++)
    {
    if(a[u][v]==1)
    {
    indegre[v]--;
    if(indegre[v]==0) s[++top]=v;
    }
    }
    }
printf("The topological Sequence :\n");
for(i=0;i<n;i++)
printf("%d ",t[i]);
}
void main()
{
int i,j;

printf("Enter the  no. of vertices:");
scanf("%d",&n);
printf("\nEnter adjacency matrix:\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
scanf("%d",&a[i][j]);
}
topology();

}