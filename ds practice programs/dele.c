#include<stdio.h>
#define max 10
void input(int *,int);
void output(int *,int);
int delarray(int *,int,int);
int main(){
   int a[max],n,position;
   printf("\nenter number of elements:\n");
   scanf("%d",&n);
   input(a,n);
   output(a,n);
   printf("\nenter position of element to be deleted:\n");
   scanf("%d",&position);
  n= delarray(a,n,position);
   output(a,n);
   return 0;
}
void input(int *b,int s){
   int i;
   for(i=0;i<s;i++){
    printf("enter values:\n");
    scanf("%d",(b+i));
   }
}
void output(int *b,int s){
  int i;
  printf("\narray values are:\n");
  for(i=0;i<s;i++){
    printf(" %d ",*(b+i));
  }
}
int delarray(int *b,int s,int pos){
  int temp,i;
  temp=b[pos-1];
  for(i=pos-1;i<s-1;i++){
    b[i]=b[i+1];
  }
  s--;
  return(s);
}
