/*                                                          IN THIS VIDEO WE ARE TALKING
                                            ABOUT HOW TO CREATE AND PERFORM OPERATIONS ON A DOUBLY LINKED LIST
*/



#define max 5
#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *prev,*next;
};
struct node *create(struct node *,int);//THIS IS A CREATION OF LINKED LIST
void traverse(struct node *);//TO DISPLAY WE HAVE CREATED A FUNCTION
void search(struct node *,int);//SEARCH A ELEMENT
struct node *insertatmiddle(struct node *,int,int);//THIS IS INSERT ANY NODE AT MIDDLE
struct node *del(struct node *,int);//DELETE ANY ELEMENT FROM A LINKED LIST
void exit();
int main(){
  struct node *start=NULL;
  int choice,n,position,item;
  while(1){
    printf("\n1.create\n2.traverse\n3.search\n4.insert at middle\n5.delete a data\n6.exit\n");
    printf("enter your choice");
    scanf("%d",&choice);
    switch(choice){
    case 1 : printf("enter no. of nodes:");
              scanf("%d",&n);
              start=create(start,n);
              break;
   case 2 : traverse(start);
               break;
   case 3 : printf("enter item to be search:");
             scanf("%d",&item);
            search(start,item);
             break;
   case 4 : printf("enter item to be insert:");
           scanf("%d",&item);
           printf("enter at which position:");
           scanf("%d",&position);
           start=insertatmiddle(start,item,position);
           break;
   case 5 : printf("enter item to be deleted:");
            scanf("%d",&item);
            start=del(start,item);
            break;
   case 6: exit(0);
             break;
   default : printf("invalid input");
    }
  }
  return 0;
}
struct node *create(struct node *start,int n){
  struct node *newnode,*temp;
  int i;
  for(i=1;i<=n;i++){
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter data to be inserted:");
    scanf("%d",&newnode->data);
     if(start==NULL){
        newnode->next=newnode->prev=NULL;
        start=temp=newnode;
     }
     else{
        newnode->next=NULL;
        newnode->prev=temp;
        temp->next=newnode;
        temp=newnode;
     }
  }
  return start;
}
void traverse(struct node *temp){
       if(temp==NULL){
        printf("list is empty");
        return;
       }
        else{
            while(temp!=NULL){
                printf(" %d ",temp->data);
                temp=temp->next;
            }
        }
}
void search(struct node *start,int item){
   struct node *temp;
   int pos=0,count=0;
   temp=start;
   if(temp==NULL){
    printf("list is empty");
    return;
   }
   else{
    while(temp!=NULL){
        pos++;
        if(temp->data==item){
        printf("%d is present at %d position",item,pos);
        count++;
        }
    temp=temp->next;
    }
   }
   if(count==0){
    printf("%d is not found",item);
   }
}
struct node *insertatmiddle(struct node *start,int item,int pos){
    struct node *temp,*newnode;
    int i;
    temp=start;
    for(i=1;i<pos-1;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("list is to short to insert item");
        return start;
    }
   newnode=(struct node *)malloc(sizeof(struct node));
   newnode->data=item;
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next->prev=newnode;
    temp->next=newnode;
    return start;
}
struct node *del(struct node *start,int item){
   struct node *q,*temp;
   temp=start;
   if(start==NULL){
    printf("list is empty");
    return start;
   }
   else if(temp->data==item){
    q=temp;
    start=start->next;
    start->next->prev=NULL;
    free(q);
    return start;
   }
   else{

    while(temp->next->next!=NULL){
        if(temp->next->data==item){
           q=temp->next;
           temp->next=temp->next->next;
           temp->next->next->prev=temp;
           free(q);
           return start;
        }
        temp=temp->next;
    }
   }
   if(temp->next->data==item){
        q=temp->next;
         temp->next=NULL;
         free(q);
    }
   return start;
}
