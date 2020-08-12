#define max 5
#include<stdio.h>
#include<stdlib.h>
struct node{
   int item;
   struct node *link;
   };
struct node *create(struct node *,int);
void search(struct node *,int);
void traverse(struct node *);
struct node *insertatbeginning(struct node *,int);
struct node *insertatlast(struct node *,int);
struct node *insertatmiddle(struct node *,int,int);
struct node *del(struct node *,int);
void exit();
int main(){
 struct node *start=NULL;
 int choice,n,data,position;
 while(1){
    printf("\n1.create linked list\n2.traverse\n3.search a data\n4.insert data at beginning\n5.insert at last\n6.insert at middle\n7.delete number\n8.exit\n");
    printf("enter your choice:");
    scanf("%d",&choice);
    switch(choice){
    case 1 : printf("enter number of nodes:");
             scanf("%d",&n);
        start=create(start,n);
        break;
    case 2 : traverse(start);
              break;
     case 3 :      printf("enter data to be search:");
                 scanf("%d",&data);
                 search(start,data);
                  break;
     case 4 : printf("enter data to be inserted:");
              scanf("%d",&data);
             start=insertatbeginning(start,data);
              break;
     case 5 : printf("enter data to be inserted:");
              scanf("%d",&data);
              start=insertatlast(start,data);
              break;
     case 6 : printf("insert number and position:");
              scanf("%d%d",&data,&position);
              start=insertatmiddle(start,data,position);
              break;
    case 7  : printf("enter data to be deleted:");
              scanf("%d",&data);
              start=del(start,data);
              break;
     case 8 : exit(0);
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
  }
  else{
    printf("enter data to %d node:",i);
    scanf("%d",&newnode->item);
    newnode->link=NULL;
  if(start==NULL){
    start=temp=newnode;
  }
  else {
    temp->link=newnode;
    temp=newnode;
       }
     }
   }
   return start;
}
void traverse(struct node *temp){
    if (temp==NULL)
        printf("list is empty");
   while(temp!=NULL){
    printf(" %d ",temp->item);
    temp=temp->link;
   }
}
void search(struct node *start,int data){
  struct node *temp;
  int pos=0,count=0;
  temp=start;
  while(temp!=NULL){
      pos++;
    if(temp->item==data){
        printf("%d is found at %d position\n",data,pos);
        count++;
    }

        temp=temp->link;

  }
  if(count==0){
    printf("%d is not found",data);
  }

}
struct node *insertatbeginning(struct node *start,int data){
   struct node *temp;
   temp=(struct node *)malloc(sizeof(struct node));
   temp->item=data;
   temp->link=start;
   start=temp;
   return start;
}
struct node *insertatlast(struct node *start,int data){
   struct node *temp,*newnode;
   newnode=(struct node *)malloc(sizeof(struct node));
   newnode->item=data;
   newnode->link=NULL;
   if(start==NULL)
    {
    start=newnode;
    return(start);
   }
else{
        temp=start;
        while(temp->link!=NULL){
    temp=temp->link;
   }
   if(temp->link==NULL){
     temp->link=newnode;
  return(start);
  }
  }
}
struct node *insertatmiddle(struct node *start,int data,int pos){
   int i;
  struct node *temp,*newnode,*q;
  if(start==NULL || pos==1){
    start=insertatbeginning(start,data);
  }
    else{
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->item=data;
        temp=start;
        q=temp->link;
        for(i=1;i<pos-1;i++)
         {
       temp=q;
       q=q->link;

   if(temp==NULL){
    printf("list is too short to add element");
        return;
   }
     temp->link=newnode;
     newnode->link=q;
     }
   }
   return start;
}
struct node *del(struct node *start,int data){
   struct node *temp,*q;
   if(start==NULL){
    printf("list is empty");
   }
   else if(start->item==data){
    temp=start;
    start=start->link;
    free(temp);
    return start;
   }
   else {
        q=start;
    while(q->link->link!=NULL){
        if(q->link->item==data){
            temp=q->link;
            q->link=q->link->link;
            free(temp);
            return start;
        }
        q=q->link;
    }
    if(q->link->link==NULL){
        temp=q->link;
        q->link=q->link->link;
        free(temp);
       return start;
    }
   }
   printf("\n element not exist");
   return start;
}
