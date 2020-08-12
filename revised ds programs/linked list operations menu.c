#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *link;
}Node;
Node *create(int,int);
void traverse(Node *);
void search(Node *,int);
Node *insertAtbeginning(Node *,int);
Node *insertAtmiddle(Node *,int,int);
Node *insertAtlast(Node *,int);
Node *del(Node *,int);
void reverse(Node *);
void exit();
int main(){
  Node *start=NULL;
  int item,choice,position,f=1,n;
  while(1){
    printf("\n1.create linked list:\n2.traverse:\n3.insert item at beginning:\n4.insert item at middle:\n5.insert item at last:\n6.delete item:\n7.search item:\n8.reverse linked list:\n9.exit:\n");
    printf("enter your choice:");
    scanf("%d",&choice);
    switch(choice){
    case 1 : printf("enter number of nodes:");
    scanf("%d",&n);
    start=create(n,f);
    break;
    case 2 : traverse(start);
    break;
    case 3 :printf("enter item to be inserted:");
    scanf("%d",&item);
        start=insertAtbeginning(start,item);
        break;
    case 4 : printf("enter item:");
    scanf("%d",&item);
    printf("enter position:");
    scanf("%d",&position);
    start=insertAtmiddle(start,position,item);
    break;
    case 5 : printf("enter item");
    scanf("%d",&item);
    start=insertAtlast(start,item);
    break;
    case 6 : printf("enter item to be deleted");
    scanf("%d",&item);
    start=del(start,item);
    break;
    case 7 : printf("enter item to be search");
    scanf("%d",&item);
        search(start,item);
        break;
    case 8: reverse(start);
    break;
    case 9:exit(0);
    break;
    default : printf("invalid choice");
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
void traverse(Node *q){
  if(q==NULL){
    printf("linked is empty");
  }
  else{
    while(q!=NULL){
        printf("%d ",q->data);
        q=q->link;
    }
  }
}
void search(Node *q,int item){
  int count=1,f=0;
  while(q!=NULL){
    if(q->data==item){
            printf("%d is present at %d position\n",item,count);
            f=1;
    }
    count++;
    q=q->link;
  }
  if(f==0)
    printf("%d is not present",item);

}
Node *insertAtbeginning(Node *q,int item){
  Node *newnode;
  newnode=(Node *)malloc(sizeof(Node));
  newnode->data=item;
  newnode->link=q;
  q=newnode;
  return q;
}
Node *insertAtlast(Node *q,int item){
  Node *newnode,*t;
  newnode=(Node *)malloc(sizeof(Node));
  newnode->data=item;
  newnode->link=NULL;
  t=q;
  while(t->link!=NULL){
    t=t->link;
  }
   t->link=newnode;
   return q;
}
Node *insertAtmiddle(Node *q,int pos,int item){
   Node *newnode,*t;
   int i;
   if(q==NULL || pos==1){
    q=insertAtbeginning(q,item);
   }
   else{
        t=q;
   for(i=1;i<pos-1;i++){
    t=t->link;
   }
   newnode=(Node *)malloc(sizeof(Node));
   newnode->data=item;
   newnode->link=t->link;
   t->link=newnode;
   }
  return q;
}
Node *del(Node *q,int item){
  Node *temp,*t;
  if(q==NULL){
    printf("list is empty");
    return q;
  }
   else if(q->data==item){
    temp=q;
    q=q->link;
    free(temp);
    return q;
  }
        t=q;
  while(t->link->link!=NULL){
    if(t->link->data==item){
        temp=t->link;
        t->link=t->link->link;
        free(temp);
        return q;
    }
  t=t->link;
}
    if(t->link->data==item){
    temp=t->link;
    t->link=NULL;
    free(temp);
    return q;
   }

   printf("item is not found");
   return q;
}
void reverse(Node *q){
    if(q==NULL)
        return;
   reverse(q->link);
   printf("%d ",q->data);
}
