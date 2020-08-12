#define max 5
#include<stdio.h>
void display(int *,int);
int push(int *,int,int,int);
int main(){
   int stack[max],item,top;
   printf("\nenter the item:\n");
   scanf("%d",&item);
  top= push(stack,max,item,top);
   display(stack,top);
   return 0;
}
void display(int *b, int s){
  int i;
  printf("\nvalues are:\n");
  for(i=0;i<s;i++)
    printf("%d",*(b+i));
}
int push(int *b,int max,int item,int top){
   int i;
   if(top==max-1){
    printf("\nstack is overflow:\n");
   }
   else if(top<max-1){
        top++;
        b[top]=item;
   }
   return(top);
}



