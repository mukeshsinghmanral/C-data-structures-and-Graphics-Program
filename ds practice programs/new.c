/* In this I have used 2 reverse technique , reverse using recursion does not change the links while simple recursion does, original linked list alignment
 of nodes is changed in simple reverse technique*/

#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *link;
};
struct node *create(int);
void traverse(struct node *);
int reverserecur(struct node *,int);
struct node *reverse(struct node *);
int main(){
    struct node *start=NULL;
    int n,choice,c=0;
while(1){
printf("\n1.create:\n2.traverse:\n3.reverse using recursion:\n4.reverse:\n5.exit:\n");
printf("enter your choice:");
scanf("%d",&choice);
   switch(choice){
   case 1 : printf("enter number of items:");
            scanf("%d",&n);
            start=create(n);
            break;
   case 2 : traverse(start);
             break;
   case 3 : c=reverserecur(start,c);
            break;
   case 4 : start=reverse(start);
             break;
   case 5 : exit(0);
          break;
   default : printf("invalid choice");
   }
}
return 0;
}
struct node *create(int n){
    if(n==0)
        return 0;
 struct node *newnode;
 newnode=(struct node *)malloc(sizeof(struct node));
 printf("enter item:");
 scanf("%d",&newnode->data);
 newnode->link=NULL;
 newnode->link=create(n-1);
return newnode;
}
void traverse(struct node *temp){
 if(temp==NULL){
    printf("linked list is empty");
 }
 else{
        printf("Linked list is:\n");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
 }

}
int reverserecur(struct node *temp,int c){
    if(c==0){
        printf("reverse using recursion is:\n");
    }
   if(temp==NULL){
    return c;
   }
   else{
        c=1;
    c=reverserecur(temp->link,c);
    printf("%d ",temp->data);
   }
}
struct node *reverse(struct node *q1){
    struct node *t,*q2,*q3;
    if(q1==NULL){
        printf("linked is empty");
    }
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
   t=q2;
   return t;
}
