#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *link;
};
struct node *create(struct node *,int);
void traverse(struct node *);
void exit();
int main(){
  struct node *start=NULL;
  int choice,n;
  printf("\t\t\t\t\t\t\t\t\t\t\t\t    CREATION AND DISPLAY OF PROGRAM");
  printf("\n\n\n");
  while(1){
    printf("\n1.create node\n2.traverse\n3.exit\n");
    printf("enter your choice:");
    scanf("%d",&choice);
    switch(choice){
    case 1 : printf("enter no. of nodes:");
             scanf("%d",&n);
             start=create(start,n);
             break;
    case 2 : traverse(start);
             break;
    case 3 : exit(0);
             break;
    default : printf("wrong input");
    }
  }
return 0;
}
struct node *create(struct node *start,int n){
   struct node *newnode,*temp;
   int i;
   for(i=1;i<=n;i++){
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter %d item:",i);
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    if(start==NULL){
        start=temp=newnode;
    }
    else{
        temp->link=newnode;
        temp=newnode;
    }
   }
   return start;
}
void traverse(struct node *temp){
   if(temp==NULL){
    printf("list is empty");
   }
   else{
    while(temp!=NULL){
        printf(" %d ",temp->data);
        temp=temp->link;
    }
   }
}
