#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
struct bit{unsigned char x:1;};

int uset[]={1,2,3,4,5,6,7,8,9};
void main()
 {
  void readset(struct bit a[],int n);
  void printset(struct bit a[]);
  void unionset(struct bit a[],struct bit b[],struct bit c[]);
  void interset(struct bit a[],struct bit b[],struct bit c[]);
  void difference(struct bit a[],struct bit b[],struct bit c[]);
  
  struct bit a[10]={0},b[10]={0},c[10]={0};
  int n;
   
  printf("Number of elements in set A:");
  scanf("%d",&n);
  readset(a,n);
  
  printf("\n Number of elements in set B:");
  scanf("%d",&n);
  readset(b,n);
 
  
  printf("\nSet A:");
  printset(a);
  
  printf("Set B:");
  printset(b);
  
  unionset(a,b,c);
  printf("A U B =");
  printset(c);
  
  interset(a,b,c);
  printf("A intersection B=");
  printset(c);
  
  difference(a,b,c);
  printf("A - B =");
  printset(c);
}
 

 

//to compute the intersection of two sets
void interset(struct bit a[],struct bit b[],struct bit c[])  
 {
  int k;
  for(k=0;k<SIZE;++k)
   c[k].x=a[k].x & b[k].x;  //intersection:set bit if present in both sets
  return;
 }
 
//to compute the difference of two sets 
void difference(struct bit a[],struct bit b[],struct bit c[])
 {
  int k;
  for(k=0;k<SIZE;++k)
   if(a[k].x==1)
    c[k].x=a[k].x^b[k].x;
  return;
 }
 
//to compute the union of two sets
void unionset(struct bit a[],struct bit b[],struct bit c[])
 {
  int k;
  for(k=0;k<SIZE;++k)
  {
   c[k].x=a[k].x | b[k].x;//union:set bit if present in either set
  }
  return;
 }
 
 
//to read a set and store as bit string
void readset(struct bit a[],int n)
 {
  int i,x,k;
  printf("\nEnter %d elements:\n",n);
  for(i=0;i<n;++i)
  {
   scanf("%d",&x);
    for(k=0;k<SIZE;++k)
    {
     if(uset[k]==x)
      {
       a[k].x=1; //set the corresponding bit to 1
       break;
      }
  }
  }
 }
 
//to  print a set
void printset(struct bit a[])
 {
  int k;
   printf("{");
  for(k=0;k<SIZE;++k)
    
     if(a[k].x==1)
      
       printf("%d",uset[k]);
       
      
     
   printf("}\n");
  return;
  
 }
  
 
