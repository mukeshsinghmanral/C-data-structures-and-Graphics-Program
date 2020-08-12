#include<stdio.h>
#define Max 10
void add_rear(int *,int,int *,int*,int);
void del_front(int *,int,int *,int *);
void traverse(int *,int *,int *,int);
void del_rear(int *,int,int *,int *);
void add_front(int *,int,int *,int *,int);
void exit();
int main(){
  int dequeue[Max],n,choice,item,front=-1,rear=-1;
  printf("enter number of items in dequeue:");
  scanf("%d",&n);
  while(1){
  printf("\n1.add from rear:\n2.delete an item front:\n3.delete an item rear:\n4.add from front:\n5.traverse:\n6.exit\n");
  printf("enter your choice:");
  scanf("%d",&choice);
  switch(choice){
  case 1 : printf("enter item to be inserted:");
  scanf("%d",&item);
  add_rear(dequeue,n,&front,&rear,item);
  break;
  case 2 : del_front(dequeue,n,&front,&rear);
  break;
  case 3 : del_rear(dequeue,n,&front,&rear);
  break;
  case 4 : printf("enter item:");
  scanf("%d",&item);
  add_front(dequeue,n,&front,&rear,item);
  break;
  case 5 : traverse(dequeue,&front,&rear,n);
  break;
  case 6 : exit();
  break;
  default: printf("invalid choice");
    }
  }
  return 0;
}
void add_rear(int *cq,int n,int *f,int *r,int item){
  if((*f)==0&&(*r)==n-1 || (*f)==(*r)+1){
    printf("dequeue is full");
    return;
  }
   if((*f)==-1&&(*r)==-1){
    (*f)=0;
    (*r)=0;
  }
  else if((*r)==n-1 && (*f)!=0)
    (*r)=0;
    else
        (*r)++;
  cq[*r]=item;
}
void del_front(int *cq,int n,int *f,int *r){
  int temp;
  if((*f)==-1 && (*r)==-1){
    printf("dequeue is empty");
    return;
    }
    temp=cq[*f];
   printf("recently deleted item:%d",temp);
   if((*f)==(*r)){
    (*f)=-1;
    (*r)=-1;
  }
  else if((*r)<(*f) && (*f)==n-1)
    (*f)=0;
  else
    (*f)++;
  }
void traverse(int *cq,int *f,int *r,int n){
  int i;
  if((*f)==-1&&(*r)==-1){
    printf("dequeue is empty");
  }
  else if((*f)<=(*r)){
     printf("dequeue is:\n");
    for(i=(*f);i<=(*r);i++){
        printf("%d ",*(cq+i));
       }
     }
    else{
        for(i=(*f);i<=n-1;i++){
            printf("%d ",*(cq+i));
        }
        for(i=0;i<=(*r);i++){
                printf("%d ",*(cq+i));
        }
    }


}
void del_rear(int *cq,int n,int *f,int *r){
  int temp;
  if((*f)==-1 && (*r)==-1){
    printf("dequeue is empty");
    return;
    }
    temp=cq[*r];
   printf("recently deleted item:%d",temp);
   if((*f)==(*r)){
    (*f)=-1;
    (*r)=-1;
  }
  else if((*r)==0)
    (*r)=n-1;
  else
    (*r)--;
  }
void add_front(int *cq,int n,int *f,int *r,int item){
  if((*f)==0&&(*r)==n-1 || (*f)==(*r)+1){
    printf("dequeue is full");
    return;
  }
   if((*f)==-1&&(*r)==-1){
    (*f)=0;
    (*r)=0;
  }
  else if((*f)==0)
    (*f)=n-1;
    else
        (*f)--;
  cq[*f]=item;
}

