#define max 5
#include<stdio.h>
void display(int *,int);
int main(){
  int a[max],i;
  printf("enter values:");
  for(i=0;i<max;i++)
  scanf("%d",(a+i));
  display(a,max);
    return 0;
}
void display(int *b,int s){
    int i;
   printf("\nvalues:\n");
  for(i=0;i<s;i++)
  printf(" %d ",*(b+i));
}
