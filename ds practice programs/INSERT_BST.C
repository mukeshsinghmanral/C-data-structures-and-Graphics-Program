#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *left,*right;
};
struct node *create();
void findlocation(struct node **,struct node **,int, struct node *);
struct node  *insert(struct node *, int);
void inorder(struct node *);
 struct node *root=NULL;
int main(){
    int choice,item;
    while(1){
   printf("\n1.create\n2.insert\n3.inorder\n4.exit\n");
   printf("enter your choice:");
   scanf("%d",&choice);
   switch(choice){
   case 1 : root=create();
            break;
   case 2 : printf("enter item to insert:");
             scanf("%d",&item);

             root=insert(root, item);
             break;
   case 3 : inorder(root);
            break;
   case 4 : exit(0);
            break;
   default : printf("invalid ");

   }
    }
    return 0;
}
struct node *create(){
    int x;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter item(-1) for finish:");
    scanf("%d",&x);
    if(x==-1){
        return 0;
    }
    else{
     newnode->data=x;
     printf("enter left child:");
     newnode->left=create();
     printf("enter right child:");
     newnode->right=create();
    }
    return newnode;

}
void findlocation(struct node **par,struct node **loc,int item, struct node *root){
  struct node *ptr,*ptrpar;
  if(root==NULL){
    *par=NULL;
    *loc=NULL;
    return;
  }
   if(item==root->data){
    *par=NULL;
    *loc=root;
    return;
  }
   if(item<root->data){
    ptr=root->left;
  }
  else{
    ptr=root->right;
  }
  ptrpar=root;
  while(ptr!=NULL){
    if(item==ptr->data){
        *par=ptrpar;
        *loc=ptr;
        return;
    }
    ptrpar=ptr;
     if(item<ptr->data)
       ptr=ptr->left;
    else
        ptr=ptr->right;
  }
  *loc=NULL;
  *par=ptrpar;
}
struct node *insert(struct node *root, int item){
  struct node *location,*parent,*newnode;

    findlocation(&parent,&location,item, root);

  if(location!=NULL){
    printf("item already exist");
    return root;
  }
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=item;
  newnode->left=newnode->right=NULL;
    if(parent==NULL){
        root=newnode;
    }
    else if(item<parent->data){
        parent->left=newnode;
    }
    else{
        parent->right=newnode;
    }
printf("\n New node inserted\n");
return root;
  }

void inorder(struct node *root){
  if(root==NULL){
    return;
  }
  else{
    if(root!=NULL){
	inorder(root->left);
	printf("%d ",root->data);
        inorder(root->right);

    }

  }
}
