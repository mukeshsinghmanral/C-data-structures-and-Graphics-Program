#include<stdio.h>
#define Max 10
void add(int *,int,int *,int*,int);
void del(int *,int,int *,int *);
void traverse(int *,int *,int *);
void exit();
int main(){
  int queue[Max],n,choice,item,front=-1,rear=-1;
  printf("enter number of items in queue:");
  scanf("%d",&n);
  while(1){
  printf("\n1.add an item:\n2.delete an item:\n3.traverse:\n4.exit\n");
  printf("enter your choice:");
  scanf("%d",&choice);
  switch(choice){
  case 1 : printf("enter item to be inserted:");
  scanf("%d",&item);
  add(queue,n,&front,&rear,item);
  break;
  case 2 : del(queue,n,&front,&rear);
  break;
  case 3 : traverse(queue,&front,&rear);
  break;
  case 4 : exit();
  break;
  default: printf("invalid choice");
    }
  }
  return 0;
}
void add(int *q,int n,int *f,int *r,int item){
  if((*r)==n-1){
    printf("queue is full");
    return;
  }
  else if((*f)==-1&&(*r)==-1){
    (*f)=0;
    (*r)=0;
  }
    else{
        (*r)++;
    }
  q[*r]=item;
}
void del(int *q,int n,int *f,int *r){
  int temp;
  if((*f)==-1 && (*r)==-1){
    printf("queue is empty");
    return;
    }
    temp=q[*f];
   printf("recently deleted item:%d",temp);
   if((*f)==(*r)){
    (*f)=-1;
    (*r)=-1;
  }
  else
    (*f)++;
  }
void traverse(int *q,int *f,int *r){
  int i;
  if((*f)==-1&&(*r)==-1){
    printf("queue is empty");
  }
  else{
        printf("queue is:\n");
    for(i=(*f);i<=(*r);i++){
        printf("%d ",*(q+i));
    }

  }
}

