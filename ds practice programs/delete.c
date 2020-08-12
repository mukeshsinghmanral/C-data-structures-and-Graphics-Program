#define max 10
#include<stdio.h>
void input(int *,int);
void output(int *,int);
int del(int *,int ,int);
int main(){
  int a[max],n,position;
  printf("enter number of elements:\n");
  scanf("%d",&n);
  input(a,n);
  output(a,n);
  printf("\nenter position:\n");
  scanf("%d",&position);
   n=del(a,n,position);
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
 printf("\nvalues are:\n");
 for(i=0;i<s;i++)
    printf(" %d ",*(b+i));
}
int del(int *b,int s,int pos){
   int i,temp;
   temp=b[pos-1];
   for(i=pos-1;i<s;i++)
    b[i]=b[i+1];
     (s)--;
     return(s);
}
