#include<stdio.h>
struct prioq
{
int dist,pr,s;
};
void display(struct prioq p[20],int source,int dest,int d)
{
if(dest==source)
{
printf("%d",source);
return;
}
display(p,source,p[dest].s,d);
printf("->%d",dest);
}
void main()
{
struct prioq p[20];
int i,j,n,k,min,pos,source,a[20][20];
printf("\nEnter the value of n:");
scanf("%d",&n);
printf("\nEnter the adjacency matrix\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
}
p[i].pr=0;
}
printf("\nEnter the source node ");
scanf("%d",&source);
for(i=0;i<n;i++)
{
p[i].s=source;
p[i].dist=a[source][i];
}
pos=source;
for(j=0;j<n;j++)
{
i=pos;
p[i].pr=-1;
min=9999;
for(k=0;k<n;k++)
{
if(p[i].dist+a[i][k]<p[k].dist)
{
p[k].dist=p[i].dist+a[i][k];
p[k].s=i;
}
if(p[k].pr!=-1&&p[k].dist<min)
{
pos=k;
min=p[k].dist;
}
}
}
for(i=0;i<n;i++)
{
printf("\n");
if(i==source)
{
printf("%d->%d",source,source);
}
else
{
display(p,source,i,i);
}
printf(" %d",p[i].dist);
}
}
