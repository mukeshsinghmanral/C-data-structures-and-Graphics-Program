#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *link;
}Node;
Node *push(Node *,int);
Node *pop(Node *);
void display(Node *);
void exit();
int main(){
 Node *top=NULL;
 int choice,item;
 while(1){
 printf("\n1.push item\n2.pop item\n3.display\n4.exit\n");
 printf("enter your choice");
 scanf("%d",&choice);
 switch(choice){
   case 1 :printf("enter item:");
   scanf("%d",&item);
   top=push(top,item);
   break;
   case 2 :top=pop(top);
   break;
   case 3 :display(top);
   break;
   case 4 :exit(0);
   break;
   default :printf("invalid choice");
 }
 }
 return 0;
}
Node *push(Node *top,int item){
  Node *newnode;
  newnode=(Node *)malloc(sizeof(Node));
  newnode->data=item;
  newnode->link=top;
  top=newnode;
  return top;
}
Node *pop(Node *top){
  Node *temp;
  if(top==NULL)
    printf("stack is empty");
    else{
       temp=top;
       printf("popped item:%d",top->data);
       top=top->link;
       free(temp);
      return top;
    }
}
void display(Node *top){
  Node *q;
  if(top==NULL)
    printf("stack is empty");
    else{
            q=top;
        while(q!=NULL){
                printf("%d\n",q->data);
            q=q->link;
        }

    }
}
