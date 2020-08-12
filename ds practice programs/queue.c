#define max 5
#include<stdio.h>
void add(int *,int *,int *,int);
void del(int *,int *,int *);
void display(int *,int *,int *);
void exit();
int main(){
int queue[max],front=-1,rear=-1,choice,item;
while(1){
    printf("\n1.add\n2.delete\n3.display\n4.exit\n");
    printf("enter your choice\n");
    scanf("%d",&choice);
    switch(choice){
    case 1 : printf("\nenter item:\n");
               scanf("%d",&item);
               add(queue,&front,&rear,item);
               break;
    case 2 : del(queue,&front,&rear);
              break;
    case 3 : display(queue,&front,&rear);
    break;
    case 4 : exit(0);
    break;
    default : printf("wrong input!");
    }
}
return 0;
}
void add(int *q,int *f,int *r,int item){
   if(*f==-1){
    *f=*r=0;
    *(q+*r)=item;
   }
   else if(*r==max-1){
    printf("queue is full!");
   }
   else {
    *r++;
   }
   *(q+*r)=item;
}
void del(int *q,int *f,int *r){
    int temp;
    temp=*(q+*f);
    if(*f==-1){
        printf("queue is empty!");
    }
    else if(*f==*r){
        *f=*r=-1;
    }
    else if(*f==max-1){
        *f=0;
    }
    else{
        *f++;
    }
}
void display(int *q,int *f,int *r){
  int i;
  if(f==-1){
    printf("queue is empty!");
  }
  else{
  printf("queue values:\n");
  for(i=*f;i<=*r;i++){
    printf("%d\n",*(q+i));
    }
  }
}
