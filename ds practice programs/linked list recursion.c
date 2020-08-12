#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *link;
};
struct node *create(int,int);
void traverse(struct node *);
int main(){
struct node *start=NULL;
  int n,choice,f=1;
  while(1){
    printf("\n1.create\n2.traverse\n3.exit\n");
    printf("enter your choice:");
    scanf("%d",&choice);
    switch(choice){
    case 1 : printf("enter no. of items:");
            scanf("%d",&n);
        start=create(n,f);
              break;
    case 2 : traverse(start);
              break;
    case 3 : exit(0);
            break;
    default : printf("invalid input");

    }

  }
  return 0;
}
 struct node *create(int n,int f){
     if(n==0){
            return 0;
        }
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter %d item:",f);
    f++;
        scanf("%d",&newnode->data);
        newnode->link=NULL;
            newnode->link=create(n-1,f);
        return newnode;
 }
 void traverse(struct node *temp){
   if(temp==NULL){
    printf("linked list is empty");
   }
   else{
        printf("linked list is:\n");
        while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->link;
   }
   }
 }
