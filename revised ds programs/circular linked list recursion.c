#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *link;
}Node;
Node *create(int,int);
void traverse(Node *);
void cirtraverse(Node *);
int main(){
  Node *start=NULL,*c;
  int item,choice,position,f=1,n;
  while(1){
    printf("\n1.create linked list:\n2.traverse:\n3.confirm\n4.exit\n");
    printf("enter your choice:");
    scanf("%d",&choice);
    switch(choice){
    case 1 : printf("enter number of nodes:");
    scanf("%d",&n);
    start=create(n,f);
    c=start;
    while(c->link!=NULL){
        c=c->link;
    }
    c->link=start;
    break;
    case 2 : traverse(c->link);
    break;
    case 3 : cirtraverse(c->link);
    break;
    case 4 :
        exit(0);
    break;
    default :printf(" invalid choice");
    }
  }
  return 0;
}
Node *create(int n,int f){
  Node *newnode;
  if(n==0){
    return 0;
  }
  newnode=(Node *)malloc(sizeof(Node));
  printf("enter node %d:",f);
  scanf("%d",&newnode->data);
  f++;
  newnode->link=NULL;
  if(newnode==NULL){
    printf("memory not allocated!");
  }
  else
    newnode->link=create(n-1,f);
return newnode;
}
void traverse(Node *c){
  Node *q;
  if(c==NULL){
    printf("linked is empty");
  }
  else{
        q=c;
    while(q->link!=c){
        printf("%d ",q->data);
        q=q->link;
    }
    printf("%d\n",q->data);
    q=q->link;
    while(q->link!=c){
        printf("%d ",q->data);
        q=q->link;
    }
    printf("%d ",q->data);
    }
}
void cirtraverse(Node *c){
    Node *q;
    printf("%d\n",c->data);
    q=c;
    while(q->link!=c){
        q=q->link;
    }
printf("%d\n",q->link->data);
printf("%d",q->link->link->data);
}
