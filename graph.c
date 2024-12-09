//DFS BFS & TOPOLOGICAL SORT

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct node  //to represent vertex and edge
{
 int data;
 int status;
 struct node * next,*point;
}node;

typedef struct topsort   //to represent vertices of topological sort
{
 int n;
 struct topsort *next;
} topsort;

int d[SIZE],f[SIZE],time;
struct node *q[SIZE];         //to maintain queue
int front=0,rear=0;   //que handling pointers
struct node *g=0;           //to store graph
struct topsort *tsort=0;   //to store topological sort order


//function to add a a vertex

void addvertex(int n)
 {
  struct node *t=(struct node *)malloc(sizeof(struct node));
  t->data=n;
  t->point=0;
  t->next=g;
  g=t;
 }
 
//function to find vertex node address of a vertex

node *find(int n)
 {
  node *t=g;
   while(t!=0 && t->data!=n)
    t=t->next;
   return t;
 }
 
//function to add an edge

void addedge(int u,int v)
 {
  node *v1,*v2,*t;
  v1=find(u);
  v2=find(v);
  t=(node *)malloc(sizeof(node));
  t->next=v1->point;
  v1->point=t;
  t->point=v2;
  return;
 }
 
//function to print a graph

void printgraph()
 {
  node *t1,*t2,*t3;
  printf("\n vertex \t edge list \n");
  t1=g;
  while(t1!=0)
   {
    printf("\n %d... \t",t1->data);
    t2=t1->point;
    while(t2!=0)
     { 
      t3=t2->point;
      printf("%d,",t3->data);
      t2=t2->next;
     }
    t1=t1->next;
   }
 }
 
//inserting nodes in topological order list at beginning

void topsorting(int n)
 {
  topsort *z=(topsort *)malloc(sizeof(topsort));
  z->n=n;
  z->next=tsort;
  tsort=z;
 }
 
 
//printing topological order list

void topsortout()
 {
  while(tsort!=0)
   {
    printf("%d,",tsort->n);
    tsort=tsort->next;
   }
 }
 
//DFS-VISIT

void dfs_visit(node *u)
 {
  node *t,*t1;
  u->status=1;   //visit vertex
  printf("%d, ",u->data);
  ++time;
  d[u->data]=time;   //store discovery time
  t=u->point;
   while(t!=0)
    { 
     t1=t->point;
     if(t1->status==0)  //if not visited
      dfs_visit(t1);
     t=t->next;
    }
    ++time;
    f[u->data]=time;  //store finish time
    topsorting(u->data);  //store the node topological sort list
    return;
 }
 
//DFS search

void dfs(node *g1)
 {
  node *t=g;
  while(t!=0)
   {
    t->status=0;   //set as not visited
    t=t->next;
   }
  dfs_visit(g1);
 }
 
//enqueue operation

void enqueue(node *s)
 {
  int r1=rear;
  r1=(r1+1)%SIZE;
  if(front==r1)
   {
    printf("Q full");
    exit(1);
   }
  rear=r1;
  q[rear]=s;
 }
 
//emptyq-to test queue is empty or not

int emptyq()
 {
  if(front==rear)
   return 1;
  else
   return 0;
 }
 
//dequeue opeartion

node *dequeue()
 {
  if(emptyq())
   {
    printf("emptyq");
    exit(2);
   }
  front=(front+1)%SIZE;
  return q[front];
 }
 
//BFS

void bfs(node *s)
 {
  node *t=g,*t1,*u;
  while(t!=0)
   {
    t->status=0;   //set all vertices are not visited
    t=t->next;
   }
  s->status=1;    //visit start vertex
  printf("%d, ",s->data);
  enqueue(s);
   while(!emptyq())
    {
     u=dequeue();
     t=u->point;
      while(t!=0) 
       {
        t1=t->point;
        if(t1->status==0)
         {
          printf("%d, ",t1->data);
          t1->status=1;
          enqueue(t1);
         }
        t=t->next;
      }
    }
 }
 
//main function to demonstrate graph searches and topological sort

void main()
 {
  addvertex(1);
  addvertex(2);
  addvertex(3);
  addvertex(4);
  addvertex(5);
  addedge(1,2);
  addedge(1,4);
  addedge(2,3);
  addedge(2,4);
  addedge(4,3);
  addedge(4,5);
  printf("The graph is:\n");
  printgraph(g);
  printf("\n DFS traverse:");
  dfs(find(1));
  
  printf("\n BFS traverse:");
  bfs(find(1));
  printf("\n topological sort order is:");
  topsortout();
 }
     
