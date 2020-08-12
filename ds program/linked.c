#define max 5
#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *link;
};
struct node *create(struct node *,int);
struct node *rev(struct node *);
void traverse(struct node *);
void exit();
int main(){
   struct node *start=NULL;
   int choice,n;
     while(1){
   printf("\n1.create\n2.reverse linked list\n3.traverse\n4.Quit\n");
   printf("enter your choice:");
   scanf("%d",&choice);

   switch(choice){
   case 1 : printf("enter no. of item to be inserted:");
            scanf("%d",&n);
            start=create(start,n);
            break;
   case 2 : start=rev(start);
            break;
   case 3 : traverse(start);
            break;
   case 4 : exit(0);
           break;
   default : printf("wrong input");
      }
  }
  return 0;
}
struct node *create(struct node *start,int n){
   struct node *temp,*newnode;
   int i;
   for(i=1;i<=n;i++){
 newnode=(struct node *)malloc(sizeof(struct node));
 if(newnode==NULL){
    printf("memory not allocated");
    return start;
 }
    else{
     printf("enter item %d:",i);
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
   }
   return start;
}
void traverse(struct node *start){
   struct node *temp;
   if(start==NULL){
    printf("list is empty");
   }
   else{
        temp=start;
         while(temp!=NULL){
            printf(" %d ",temp->data);
            temp=temp->link;
         }
   }
}
struct node *rev(struct node *start){
   struct node *q1,*q2,*q3;
   if(start==NULL){
    printf("list is empty");
   }
   else{
       q1=start;
       q2=q1->link;
       q3=q2->link;
     q1->link=NULL;
     q2->link=q1;
     while(q3!=NULL){
        q1=q2;
        q2=q3;
        q3=q3->link;
        q2->link=q1;
     }
      start=q2;
   }
 return q2;
}
