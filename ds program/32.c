#define max 5
#include<stdio.h>
void add(int *,int *,int *,int);
void display(int *,int *,int *);
int main(){
 int queue[max],front=-1,rear=-1,item,i;
 for(i=0;i<max;i++){
        printf("enter item to be inserted:\n");
 scanf("%d",&item);
 add(queue,&front,&rear,item);
   }
   display(queue,&front,&rear);
 return 0;
}
void add(int *q,int *f,int *r,int item){
   if(*f==-1&& *r==-1){
      (*f)=(*r)=0;
    *(q+*r)=item;
   }
   else if(*r==max-1){
    printf("queue is full!\n");
   }
   else{
    (*r)++;
    *(q+*r)=item;
   }
}
void display(int *q,int *f,int *r){
  int i;
  if(*f==-1&& *r==-1){
    printf("stack is empty!\n");
  }
  else {
    printf("stack values:\n");
    for(i=*f;i<=*r;i++){
        printf(" %d ",*(q+i));
    }
  }
}
