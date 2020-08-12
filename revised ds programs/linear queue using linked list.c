#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *link;
}Node;
void  add(int);
void del();
void display();
void exit();
Node *front=NULL,*rear=NULL;
int main(){
  int choice,item;
  while(1){
  printf("\n1.add item\n2.delete item\n3.display\n4.exit\n");
  printf("enter your choice");
  scanf("%d",&choice);
  switch(choice){
  case 1  : printf("enter item:");
  scanf("%d",&item);
  add(item);
  break;
  case 2 : del();
  break;
  case 3 : display();
  break;
  case 4 :exit(0);
  break;
  default : printf("invalid item");
  }
  }
  return 0;
}
void add(int item){
  Node *newnode;
  newnode=(Node *)malloc(sizeof(Node));
  newnode->data=item;
  newnode->link=NULL;
  if(front==NULL && rear==NULL){
      front=rear=newnode;
  }
  else{
    rear->link=newnode;
    rear=newnode;
  }
}
void del(){
  Node *temp;
  if(front==NULL && rear==NULL){
    printf("QUEUE IS EMPTY");
    return;
  }
  temp=front;
  printf("deleted item:%d",front->data);
  front=front->link;
  free(temp);
   if(front==NULL){
    rear=NULL;
  }
}
void display(){
  Node *q;
  if(front==NULL){
    printf("QUEUE IS EMPTY");
  }
  else{
    q=front;
    while(q!=NULL){
            printf("%d ",q->data);
        q=q->link;
    }
  }
}
