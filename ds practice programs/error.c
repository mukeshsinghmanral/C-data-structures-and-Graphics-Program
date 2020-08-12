#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *left,*right;
};
struct node *create(struct node *);
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);
 void insert(struct node *,int);
void exit();
int main(){
    printf("\t\t\t\t\t\t\t\t\t\t------------------------------------TRAVERSALS OF A BINARY TREE-----------------------------------------------");
    printf("\n\n\n\n\n\n\n\n");
    struct node *root=NULL,*newnode;
    int choice,item;
    char ch;
    while(1){
    printf("\n1.create tree\n2.preorder\n3.inorder\n4.postorder\n5.insert an item\n6.exit\n");
    printf("enter your choice:");
    scanf("%d",&choice);
    switch(choice){
    case 1 :do{
             create(root);
           printf("enter choice:");
           scanf("%c",&choice);
    }while(ch=='y' || ch=='Y');
            break;
    case 2 : preorder(root);
            break;
    case 3 : inorder(root);
            break;
    case 4 : postorder(root);
            break;
    case 5 : printf("item to be inserted:");
             scanf("%d",&item);
            insert(root,item);
            break;
    case 6 : exit(0);
     break;
     default : printf("invalid choice");
      }
    }
return 0;
}
 struct node *create(struct node *root){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
     printf("enter data:");
     scanf("%d",&newnode->data);
     newnode->left=newnode->right=NULL;
     if(root==NULL)
        root=newnode;
     else{
        if(newnode->data<root->data){
            if(root->left!=NULL){
                create(root->left);
            }
            else{
                root->left=newnode;
            }
        }
        else{
            if(root->right!=NULL){
                create(root->right);
            }
            else{
                root->right=newnode;
            }
        }
     }
 }

void preorder(struct node *root){
   if(root==NULL)
    return;
    printf(" %d ",root->data);
  preorder(root->left);
  preorder(root->right);
}
void inorder(struct node *root){
  if(root==NULL)
    return;
  inorder(root->left);
  printf(" %d ",root->data);
  inorder(root->right);
}
void postorder(struct node *root){
 if(root==NULL)
    return;
 postorder(root->left);
 postorder(root->right);
 printf(" %d ",root->data);
}

 void insert(struct node *root,int item){
  struct node *par,*newnode;
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->left=NULL;
  newnode->right=NULL;
  newnode->data=item;
  if(root==NULL){
    root=newnode;
  }
  else{
    par=root;
    while(par!=NULL){
            if(par->data>item){
        if(par->left==NULL){
            par->left=newnode;
        }
        par=par->left;
            }
        else{
            if(par->right==NULL)
                par->right=newnode;
            par=par->right;
         }
     }

  }

}
