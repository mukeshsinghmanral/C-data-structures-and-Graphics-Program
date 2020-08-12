#define max 5
#include<stdio.h>
void add(int *,int *,int *,int);
void del(int *,int *,int *);
void display(int *,int *,int *);
void exit();
int main(){
  int cqueue[max],item,choice,front=-1,rear=-1;
  while(1){
    printf("\n1.add an element:\n2.delete an element:\n3.display:\n4.exit\n");
    printf("enter your choice:\n");
    scanf("%d",&choice);
    switch(choice){
    case 1 : printf("enter an element:\n");
             scanf("%d",&item);
             add(cqueue,&front,&rear,item);
             break;
    case 2 : del(cqueue,&front,&rear);
              break;
    case 3 : display(cqueue,&front,&rear);
              break;
    case 4 : exit(0);
    }
  }
  return 0;
}
void add(int *cq,int *f,int *r,int item){
   if(*f==-1 && *r==-1){
    (*f)=(*r)=0;
    *(cq+*r)=item;
}
  else if(((*r)+1)%max==(*f)){
    printf("cqueue is full!");
  }
  else{
    (*r)=((*r)+1)%max;
    *(cq+*r)=item;
  }
}
void del(int *cq,int *f,int *r){
   int temp;
  if(*f==-1 && *r==-1)
    printf("cqueue is empty");
  else if(*f==*r){
    printf("last deleted item:%d",*(cq+*f));
    *f=*r=-1;
  }
  else{
      temp=*(cq+*f);
        printf("recently deleted item:%d",temp);
        (*f)=((*f)+1)%max;
  }
}
void display(int *cq,int *f,int *r){
  int i;
  if(*f==-1 && *r==-1)
    printf("cq is empty");
    else if(*f<=*r){
            for(i=*f;i<=*r;i++)
        printf("%d\n",*(cq+i));
    }
  else {
        for(i=*f;i<=max-1;i++)
            printf("%d\n",*(cq+i));
        for(i=0;i<=*r;i++)
            printf("%d\n",*(cq+i));
  }
}
