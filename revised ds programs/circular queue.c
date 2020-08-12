#include<stdio.h>
#define Max 10
void add(int *,int,int *,int*,int);
void del(int *,int,int *,int *);
void traverse(int *,int *,int *,int);
void exit();
int main(){
  int cqueue[Max],n,choice,item,front=-1,rear=-1;
  printf("enter number of items in queue:");
  scanf("%d",&n);
  while(1){
  printf("\n1.add an item:\n2.delete an item:\n3.traverse:\n4.exit\n");
  printf("enter your choice:");
  scanf("%d",&choice);
  switch(choice){
  case 1 : printf("enter item to be inserted:");
  scanf("%d",&item);
  add(cqueue,n,&front,&rear,item);
  break;
  case 2 : del(cqueue,n,&front,&rear);
  break;
  case 3 : traverse(cqueue,&front,&rear,n);
  break;
  case 4 : exit();
  break;
  default: printf("invalid choice");
    }
  }
  return 0;
}
void add(int *cq,int n,int *f,int *r,int item){
  if((*f)==0&&(*r)==n-1 || (*f)==(*r)+1){
    printf("cqueue is full");
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
void del(int *cq,int n,int *f,int *r){
  int temp;
  if((*f)==-1 && (*r)==-1){
    printf("cqueue is empty");
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
    printf("cqueue is empty");
  }
  else if((*f)<=(*r)){
     printf("cqueue is:\n");
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


