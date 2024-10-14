//circular queue operation.

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int front=0,rear=0;
int que[SIZE];

void main()
{
 void insertq(int);
 int deleteq();
 int searchq(int);
 int data,opt,ans;
 
 do
   {
    printf("\n1.Insert \n");
    printf("2.Delete \n");
    printf("3.Search \n");
    printf("4.Exit \n");
    printf("Enter your option:");
    scanf("%d",&opt);
  
 switch(opt)
  {
   case 1: 
          printf("Data:");
          scanf("%d",&data);
          insertq(data);
          break;
   case 2: 
          printf("Deleted data:%d",deleteq());
          break;
   case 3: 
          printf("Search data:");
          scanf("%d",&data);
          ans=searchq(data);
           if(ans==1)
             printf("Found \n");
           else
             printf("Not found \n");
          break;
   case 4: 
          exit(0);
  }
  }
  while(1);
 }
 
//function to insert an itm in circular queue.
 
 void insertq(int item)
  {
   int trear=rear;
   trear=(trear+1)%SIZE;
    if(trear==front)
      printf("QUEUE IS FULL");
    else
      { 
       rear=trear;
       que[rear]=item;
      }
    return;
   }
   
//delete an item from circular queue.
 
 int deleteq()
  {
   if(front==rear) {
    printf("QUEUE IS EMPTY \n");
    exit(1);
   }
    front=(front+1)%SIZE;
    return que[front];
  }
  
//function to search an element in circular queue.

int searchq(int item)
 {
  int tfront=front;
  if(tfront!=rear)
   {
  
  
  tfront=(tfront+1)%SIZE;
    while(tfront!=rear && que[tfront]!=item)
      tfront=(tfront+1)%SIZE;
        if(que[tfront]==item)
          return 1;
        else
          return 0;
          }
          return 0;
 }

   
   
                            
