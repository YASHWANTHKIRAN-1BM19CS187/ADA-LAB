#include<stdio.h>
#define size 20
#define true 1
#define false 0
int queue[size],visit[20],rear=-1,front=0;
int n,s,adj[20][20],flag=0;
void insertq(int v)
{
    queue[++rear]=v;
}

int deleteq()
{
    return(queue[front++]);
}

int qempty()
{

  if(rear<front)
    return 1;

  else
    return 0;
}

void bfs(int v)
{
  int w;
  visit[v]=1;
  insertq(v);

  while(!qempty())
  {
    v=deleteq();
    for(w=1;w<=n;w++)

       if((adj[v][w]==1) && (visit[w]==0))
       {
              visit[w]=1;
              flag=1;
              printf("v%d\t",w);
              insertq(w);
       }
   }
}

void main()
{
    int v,w;
    printf("Enter the no.of vertices:\n");
    scanf("%d",&n);
    printf("Enter adjacency matrix:");
    for(v=1;v<=n;v++)
    {
      for(w=1;w<=n;w++)
       scanf("%d",&adj[v][w]);
    }
    printf("Enter the start vertex:");
    scanf("%d",&s);
    printf("Reachability of vertex %d\n",s);
    for(v=1;v<=n;v++)
            visit[v]=0;

    bfs(s);

    if(flag==0)
    {
      printf("No path found!!\n");
    }
}