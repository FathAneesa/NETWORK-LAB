#include<stdio.h>
#include<stdlib.h>

int i,j,k,u,v,rv,ru,n,ne=1;
int min,mincost=0,cost[9][9],parent[9];

//find the set reference

int find(int u)
 {
  while(parent[u])
   {
    u=parent[u];
   }
  return u;
 }
 
//union of two sets

void uni(int ru,int rv)

 {
  parent[rv]=ru;
  
 }
 
void main()
 {
  printf("\n Enter the number of vertices:");
  scanf("%d",&n);
  printf("\n Enter the cost adjacency matrix: \n");
   for(i=1;i<=n;i++)
    {
     for(j=1;j<=n;j++)
      {
       scanf("%d",&cost[i][j]);
       if(cost[i][j]==0)
        cost[i][j]=999;   //if no edge,its weight is infinite
      }
      
    }
    
  printf("The edges of minimum cost spanning tree are \n");
  while(ne<n)
   {
    min=999;
    for(i=1;i<=n;i++)
     {
      for(j=1;j<=n;j++)
       {
        if(cost[i][j]<min)
         {
          min=cost[i][j];
          u=i;
          v=j;
         }
        }
      }
     ru=find(u);
     rv=find(v);
     if(ru!=rv)
      {
       uni(ru,rv);
        printf("%d edge (%d,%d) = %d \n",ne,u,v,min);
        mincost+=min;
        ne++;   //increment the edge count
      }
    cost[u][v]=cost[v][u]=999;
   }
  printf("\n\t Minimum cost=%d \n",mincost);
 }
