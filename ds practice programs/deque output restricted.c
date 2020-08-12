#define max 5
#include<stdio.h>
void add_rear(int *,int *,int *,int);
void add_front(int *,int *,int *,int);
void del_front(int *,int *,int *);
void display(int *,int *,int *);
void exit();
int main(){
  int cqueue[max],choice,item,front=-1,rear=-1;
  while(1){
    printf("\n1.add from rear\n2.add from front\n3.delete element\n4.display\n5.exit\n");
    printf("enter your choice:");
    scanf("%d",&choice);
    switch(choice){
    case 1 : printf("enter item to be added:");
              scanf("%d",&item);
              add_rear(cqueue,&front,&rear,item);
              break;
    case 2 : printf("enter item to be added:");
               scanf("%d",&item);
               add_front(cqueue,&front,&rear,item);
               break;
    case 3 : del_front(cqueue,&front,&rear);
             break;
    case 4 : display(cqueue,&front,&rear);
              break;
    case 5 : exit(0);
             break;
    default : printf("invalid input");
    }
  }
  return 0;
}
void add_rear(int *cq,int *f,int *r,int item){
   if(*f==-1 && *r==-1){
    *f=*r=0;
    *(cq+*r)=item;
   }
   else if(((*r)+1)%max==*f){
    printf("cqueue is full");
   }
   else{
    *r=((*r)+1)%max;
   *(cq+*r)=item;
   }
}
void add_front(int *cq,int *f,int *r,int item){
   if(*f==-1 && *r==-1){
    *f=*r=0;
    *(cq+*f)=item;
   }
   else if(*f==0){
    *f=max-1;
    *(cq+*f)=item;
   }
   else if((*f==0 && *r==max-1)|| (*f==(*r)+1)){
    printf("cqueue is full");
   }
   else {
        (*f)--;
    *(cq+*f)=item;
   }
}
void del_front(int *cq,int *f,int *r){
  int temp;
   if(*f==-1 & *r==-1)
    printf("cqueue is empty");
    else if(*f==*r){
        temp=*(cq+*f);
        printf("recently deleted item:%d",temp);
        *f=*r=-1;
    }
    else{
        temp=*(cq+*f);
        printf("recently deleted item:%d",temp);
        *f=((*f)+1)%max;
    }
}
void display(int *cq,int *f,int *r){
  int i;
  if(*f==-1 && *r==-1)
    printf("cqueue is empty");
  else if(*f<=*r){
    for(i=*f;i<=*r;i++)
        printf("%d\n",*(cq+i));
  }
  else{
    for(i=*f;i<=max-1;i++)
        printf("%d\n",*(cq+i));
    for(i=0;i<*r;i++)
        printf("%d\n",*(cq+i));
  }
}

