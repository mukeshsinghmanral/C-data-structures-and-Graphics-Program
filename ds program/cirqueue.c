#define max 5
#include<stdio.h>
void add(int *,int *,int *,int);
void del(int *,int *,int *);
void display(int *,int *,int *);
void exit();
int main(){
  int cqueue[max],choice,item,front=-1,rear=-1;
  while(1){
  printf("\n1.add\n2.delete\n3.display\n4.exit\n");
  printf("enter your choice\n");
  scanf("%d",&choice);
  switch(choice){
  case 1 : printf("enter item\n");
              scanf("%d",&item);
              add(cqueue,&front,&rear,item);
              break;
  case 2 : del(cqueue,&front,&rear);
   break;
   case 3 : display(cqueue,&front,&rear);
   break;
   case 4 : exit(0);
   break;
   default : printf("invalid input");
    }
  }
    return 0;
}
void add(int *cq,int *f,int *r,int item){
if((*f==0 && *r==max-1) || (*f)==(*r)+1)
    printf("cq is full");
else{
    if(*f==-1 && *r==-1){
    *f=*r=0;
    *(cq+*r)=item;
    }
   else if(*r==max-1){
    *r=0;
    *(cq+*r)=item;
    *(r)++;
   }
   else {
    *(cq+*r)=item;
    *(r)++;
   }
    }
}
void del(int *cq,int *f,int *r){
  if(*f==-1 && *r==-1)
    printf("cq is empty");
    else if(*f==*r){
            printf("last element deleted:%d",*(cq+*f));
        *f=*r=-1;
    }
    else if(*f==max-1)
    *f=0;
  else{
    printf("recently deleted item:%d",*(cq+*f));
    (*f)++;
  }
}
void display(int *cq,int *f,int *r){
   int i;
   if(*f==-1&& *r==-1)
    printf("cqueue is empty");
   else if(*f<=*r){
    for(i=*f;i<=*r;i++){
        printf("%d\n",*(cq+i));
    }
   }
   else{
    for(i=*f;i<=max-1;i++){
        printf("%d\n",*(cq+i));
    }
   for(i=0;i<*r;i++){
    printf("%d\n",*(cq+i));
     }
   }
}
