#include<stdio.h>
#include<stdlib.h>
void add(int);
void del();
void display();
void exit();
typedef struct node{
   struct node *link;
}Node;
Node *front=NULL,*rear=NULL;
int main(){
 int choice,item;
 while(1){
    printf("\n1.add item:\n2.delete item:\n3.display:\n4.exit\n");
    printf("enter your choice");
    scanf("%d",&choice);
    switch(choice){
    case 1 : printf("enter item:");
    scanf("%d",&item);
    add(item);
    break;
    case 2 : del();
    break;
    case 3 : display();
    break;
    case 4 : exit(0);
    break;
    default : printf("invalid choice");
    }
 }
 return 0;
}
void add(int item){
  Node *newnode;
  newnode=(Node *)malloc(sizeof(Node));
  newnode->data=item;
  if(front==NULL && rear==NULL){
    front=rear=newnode;
    rear->link=newnode;
  }
  else{
    rear->link=newnode;
    newnode->link=front;
    rear=newnode;
  }
}
void del(){
 Node *temp;
 if(front==NULL && rear==NULL){
    printf("queue is empty");
    return;
 }
 temp=front;
 printf("deleted item:%d",front->data);
  if(front==rear){
    front=rear=NULL;
    free(temp);
  }
  else{
    front=front->link;
    rear->link=front;
    free(temp);
  }
}
void display(){
  Node *q;
  if(front==NULL && rear==NULL)
    printf("queue is empty");
  else{
    q=front;
    while(q->link!=front){
        printf("%d ",q->data);
        q=q->link;
    }
    printf("%d\n",q->data);
  }
  printf("%d\n",rear->data);
  printf("%d",rear->link->data);
}
