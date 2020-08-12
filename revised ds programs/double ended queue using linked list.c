#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *link;
}Node;
Node *front=NULL,*rear=NULL;
void add_rear(int);
void del_front();
void add_front(int);
void del_rear();
void display();
int main(){
 int choice,item;
 while(1){
    printf("\n1.add item from rear:\n2.add item from front:\n3.delete from front:\n4.delete from rear\n5.display:\n6.exit\n");
    printf("enter your choice:");
    scanf("%d",&choice);
    switch(choice){
    case 1 : printf("enter item:");
    scanf("%d",&item);
    add_rear(item);
    break;
    case 2 :printf("enter item:");
    scanf("%d",&item);
        add_front(item);
        break;
    case 3 : del_front();
    break;
    case 4 : del_rear();
    break;
    case 5 : display();
    break;
    case 6 : exit(0);
    break;
    default : printf("invalid choice");
    }
 }
 return 0;
}
void add_rear(int item){
  Node *newnode;
  newnode=(Node *)malloc(sizeof(Node));
  newnode->data=item;
  newnode->link=NULL;
  if(front==NULL && rear==NULL){
    front=rear=newnode;
  }
  else{
    rear->link=newnode;
    rear=rear->link;
  }
}
void add_front(int item){
  Node *newnode;
  newnode=(Node *)malloc(sizeof(Node));
  newnode->data=item;
  if(front==NULL&&rear==NULL){
    newnode->link=NULL;
    front=rear=newnode;
  }
  else{
    newnode->link=front;
    front=newnode;
  }
}
void del_front(){
  Node *temp;
  if(front==NULL && rear==NULL){
    printf("dequeue is empty");
    return;
  }
  temp=front;
  if(rear==front){
        printf("deleted item:%d",front->data);
    rear=front=NULL;
    free(temp);
  }
  else{
      printf("deleted item:%d",front->data);
    front=front->link;
    free(temp);
  }
}
void del_rear(){
   Node *temp;
   if(front==NULL && rear==NULL){
    printf("dequeue is empty");
   return;
   }
   temp=front;
   if(front==rear){
        printf("deleted item:%d",temp->data);
    front=rear=NULL;
    free(temp);
   }
   else{
   while(temp->link!=rear){
    temp=temp->link;
   }
   printf("deleted item:%d",temp->link->data);
   temp->link=NULL;
   rear=temp;
   }
}
void display(){
  Node *q;
  if(front==NULL && rear==NULL){
    printf("dequeue is empty");
    return;
  }
  q=front;
  while(q!=NULL){
        printf("%d ",q->data);
    q=q->link;
  }
}
