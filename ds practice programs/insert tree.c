#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *left,*right;
};
void findlocation(struct node **,struct node **,int, struct node *);
struct node  *insert(struct node *, int);
void inorder(struct node *);
void preorder(struct node *);
struct node *del(struct node *,int);
void del_case1(struct node *,struct node *,struct node *);
void del_case2(struct node *,struct node *,struct node *);
void del_case3(struct node *,struct node *,struct node *);
void exit();
int main(){
    printf("\t\t\t\t\t\t\t\t--------------------------OPRERATIONS------------------------------");
    printf("\n\n\n");
  int choice,item;
  struct node *root=NULL;
  while(1){
    printf("\n1.insert\n2.inorder\n3.delete\n4.preorder\n5.exit\n");
    printf("enter your choice:");
    scanf("%d",&choice);
    switch(choice){
    case 1 : printf("item to be inserted:");
             scanf("%d",&item);
             root=insert(root,item);
             break;
    case 2 : inorder(root);
    break;
    case 3 :printf("enter item to be deleted:");
           scanf("%d",&item);
        root=del(root,item);
        break;
        case 4 : preorder(root);
        break;
    case 5 : exit(0);
    break;
    default : printf("invalid");
    }

  }
  return 0;
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
struct node *del(struct node *root,int item){
  struct node *parent,*location;
  if(root==NULL){
    printf("tree is empty");
    return root;
  }
  findlocation(&parent,&location,item,root);
  if(location== NULL){
    printf("item not found");
    return root;
  }
  if(location->left==NULL && location->right==NULL){
    del_case1(parent,location,root);
  }
  else if(location->left!=NULL && location->right==NULL){
    del_case2(parent,location,root);
  }
  else if(location->left==NULL && location->right!=NULL){
    del_case2(parent,location,root);
  }
  else{
    del_case3(parent,location,root);

  }
  free(location);
  return root;
}
void del_case1(struct node *par,struct node *loc,struct node *root){
   if(loc==par->left){
    par->left=NULL;
   }
   else if(loc==par->right){
    par->right=NULL;
   }
   else{
    root=NULL;
   }
   return;
}
void del_case2(struct node *par,struct node *loc,struct node *root){
   struct node *child;
   if(loc->left!=NULL){
    child=loc->left;

   }
   else{
    child=loc->right;
   }
   if(loc==par->left){
    par->left=child;
   }
   else if(loc==par->right){
    par->right=child;
   }
   else{
    root=child;
   }
   return;
}
void del_case3(struct node *par,struct node *loc,struct node *root){
   struct node *succ,*parsucc,*ptr,*parptr;
   parptr=loc;
   ptr=loc->right;
   while(ptr->left!=NULL){
    parptr=ptr;
    ptr=ptr->left;
   }
   succ=ptr;
   parsucc=parptr;
   if(succ->left==NULL && succ->right==NULL){
    del_case1(parsucc,succ,root);
   }
   else{
    del_case2(parsucc,succ,root);
   }
   if(loc==par->left){
    par->left=succ;
   }
   else if(loc==par->right){
    par->right=succ;
       }
  else {
    root=succ;
  }
       succ->left=loc->left;
    succ->right=loc->right;

return;
}
void preorder(struct node *root){
   if(root==NULL)
   return;
   else{
        if(root!=NULL){
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
        }
   }
}
