#define max 5
#include<stdio.h>
void add(int *,int *,int *,int);
void del_rear(int *,int *,int *);
void del_front(int *,int *,int *);
void display(int *,int *,int *);
void exit();
int main(){
  int choice,cqueue[max],front=-1,rear=-1,item;
  while(1){
  printf("\n1.add element\n2.delete from rear\n3.delete from front\n4.display\n5.exit\n");
  printf("enter your choice:");
  scanf("%d",&choice);
  switch(choice){
      case 1 : printf("enter element:");
               scanf("%d",&item);
               add(cqueue,&front,&rear,item);
               break;
      case 2 : del_rear(cqueue,&front,&rear);
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
void add(int *cq,int *f,int *r,int item){
     if(*f==-1 && *r==-1){
        *f=*r=0;
        *(cq+*r)=item;
     }
     else if(((*r)+1)%max==*f){
        printf("cqueue is full");
     }
     else {
        *r=((*r)+1)%max;
        *(cq+*r)=item;
     }
}
void del_front(int *cq,int *f,int *r){
    int temp;
     if(*f==-1 && *r==-1 )
        printf("cqueue is empty");
     else if(*f==*r){
            printf("recently deleted item:%d",*(cq+*f));
        *f=*r=-1;
     }
     else{
            temp=*(cq+*f);
          printf("recently deleted item:%d",temp);
     *f=((*f)+1)%max;
     }
}
 void del_rear(int *cq,int *f,int *r){
     int temp;
     if(*f==-1 && *r==-1){
        printf("cqueue is empty");
     }
     else if(*r==*f){
            printf("recently deleted:%d",*(cq+*r));
        *r=*f=-1;
     }
     else if(*r==0){
            temp=*(cq+*r);
            printf("recently deleted:%d",temp);
        *r=max-1;
     }
     else {
        temp=*(cq+*r);
        printf("recently deleted :%d",temp);
        (*r)--;
   }
}

  void display(int *cq,int *f,int *r){
    int i;
  if(*f==-1 &*r==-1)
    printf("cqueue is empty");
    else if(*f<=*r){
        for(i=*f;i<=*r;i++)
            printf("%d\n",*(cq+i));
    }
    else{
        for(i=*f;i<=max-1;i++)
            printf("%d\n",*(cq+i));
        for(i=0;i<=*r;i++)
            printf("%d\n",*(cq+i));
    }
  }





